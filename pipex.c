/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:39:30 by codespace         #+#    #+#             */
/*   Updated: 2025/07/04 13:02:20 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv, char **envp)
{
    int pipe_fd[2];
    pid_t pid;
    pid_t pid_parent;
    
    if (argc < 4)
    {
        printf("ERROR\n"); //TODO tiene que tener su correspondiente salida de error
        exit(1);
    }
    if (pipe(pipe_fd) == -1)
    {
        perror("Error en la pipe\n");
        exit(1);
    }
    pid = fork();
    if (pid == -1)
    {
        perror("Error en el fork\n");
        exit(1);
    }
    if (pid == 0)
    {
        close(pipe_fd[0]);
        dup2(pipe_fd[1], STDOUT_FILENO);
        close(pipe_fd[1]);
    }
    return (0);
}