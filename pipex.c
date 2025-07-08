/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:39:30 by codespace         #+#    #+#             */
/*   Updated: 2025/07/08 18:52:32 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_err(void)
{
    perror("ERROR");
    exit(EXIT_FAILURE);
}

char **get_path(char **envp)
{
    char *l_path;
    char **c_path;
    char **path;
    int i;

    l_path = NULL;
    i = 0;
    while (envp[i] != NULL)
    {
        if (ft_strncmp("PATH", envp[i], 4) == 0)
        {
            l_path = ft_strdup(envp[i]);
            break;
        }
        i++;
    }
    c_path = ft_split(l_path, '=');
    free(l_path);
    path = ft_split(c_path[1], ':');
    i = 0;
    while(c_path[i])
    {
        free(c_path[i]);
        i++;
    }
    return (path);
}

char *procces_cmd(char **procces_text, char *argv)
{
    char *cmd;
    char *join_path;
    int i;
    
    i = 0;
    while (procces_text[i] != NULL)
    {
        cmd = ft_strjoin(procces_text[i], "/"); 
        join_path = ft_strjoin(cmd, argv);
        if (access(join_path, X_OK))
        {
            break;
        }
        free(cmd);
        free(join_path);
    }
    return(join_path);
}

int main(int argc, char **argv, char **envp)
{
    int pipe_fd[2];
    pid_t pid;
    pid_t pid_parent;
    
    if (argc < 5 || pipe(pipe_fd) == -1)
        ft_err();
    pid = fork();
    if (pid == -1)
        ft_err();
    if (pid == 0)
        child_proc(pipe_fd, argv, envp);
    else
    {
        pid_parent = fork();
        if (pid_parent == -1)
            ft_err();
        if (pid_parent == 0)
            parent_proc(pipe_fd, argv, envp);
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        waitpid(pid, NULL, 0);
        waitpid(pid_parent, NULL, 0);
    }
    return (0);
}
