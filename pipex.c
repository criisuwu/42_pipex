/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:39:30 by codespace         #+#    #+#             */
/*   Updated: 2025/07/08 16:22:53 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include "libft/libft.h"

char **get_path(char **envp)
{
    char *l_path;
    char **c_path;
    char **path;
    int i = 0;
    
    while (envp[i] != NULL)
    {
        if (ft_strncmp("PATH", envp[i], 6))
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
    while (path != NULL)
    {
        free(c_path[i]);
        i++;
    }
    return (path);
}

//Aqui tengo que gestioanar el path, el abrir el archivo y ejecutar el archivo
char *procces_cmd(char **procces_text, char *argv)
{
    char *cmd;
    char *join_path;
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (procces_text[i] != NULL)
    {
        cmd = ft_strjoin(procces_text[i], "/");
        join_path = ft_strjoin(cmd, argv);
        if (access(join_path, X_OK))
        {
            break;
        }
        while(path[j])
        {
            free(path);
            i++;
        }
        while(c_path[j])
        {
            free(c_path);
            i++;
        }
        free(l_path);
        free(cmd);
        free(join_path);
    }
    return(join_path);
}

int main(int argc, char **argv, char **envp)
{
    char *exe;
    char **procces_text;
    int pipe_fd[2];
    pid_t pid;
    pid_t pid_parent;
    
    if (argc < 3)
    {
        perror("Error de argumentos\n");
    }
    if (pipe(pipe_fd) == -1)
    {
        perror("Error en la pipe\n");
        return(1);
    }
    pid_parent = fork();
    if (pid_parent == -1) //si da error en la crecion del hijo
    {
        perror("Error en el fork\n");
        return(1);
    }
    if (pid_parent == 0) //El proceso hijo, ejecuto el primer comando
    {
        close(pipe_fd[0]); //to look
        dup2(pipe_fd[0], STDOUT_FILENO); //to look
        //close(pipe_fd[1]);
        //Procesamos los argumentos que recibe. Es decir hacemos de primeras un split.
        procces_text = get_path(envp);
        exe = procces_cmd(procces_text, argv[1]);
        // for (int i = 0; exe != NULL; i++)
        //     printf("%s\n", exe);
        exit(1);
    }
    else //Cualquier otro pid es el proceso del padre
    {
        //Aqui tengo que realizar otro fork y en ellos son donde se procesan y ejecutan los comandos
        printf("En el padre");
        close(pipe_fd[0]);
        dup2(pipe_fd[1], STDOUT_FILENO);
        close(pipe_fd[1]);
        printf("antes de procesar los argumentos");
        //Procesamos los argumentos que recibe. Es decir hacemos de primeras un split.
        exe = procces_cmd(argv[1], envp);
        // for (int i = 0; exe != NULL; i++)
        //     printf("%c\n", exe[i]);
        exit(1);
    }
}
