/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:39:30 by codespace         #+#    #+#             */
/*   Updated: 2025/07/03 15:20:45 by codespace        ###   ########.fr       */
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
    pid = fork();
    if (pid == -1)
    {
        perror("Error en el fork");
        exit(1);
    }
    if (pid == 0)
    {
        close(pipe_fd[0]);
        dup2(pipe_pid[1], STDOUT_FILENO);
    }
    return (0);
}