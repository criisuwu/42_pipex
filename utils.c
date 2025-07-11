/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:26:50 by chomobon          #+#    #+#             */
/*   Updated: 2025/07/11 12:24:30 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Gestiono lo que hace el hijo y la posibilidad de crear un nuevo archivo o
//de modificar el archivo ya creado
void parent_proc(int *pipe_fd, char **argv, char **envp)
{
    int file_fd;

    close(pipe_fd[1]);
    file_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC , 0666);
    if(file_fd == -1)
        ft_err();
    if (dup2(pipe_fd[0], STDOUT_FILENO) == -1)
        ft_err();
    if (dup2(file_fd, STDOUT_FILENO) == -1)
        ft_err();
    close(pipe_fd[0]);
    ex_cmd(argv[3], envp);
}

//Gestiono el archivo a abrir para el hijo
void child_proc(int *pipe_fd, char **argv, char **envp)
{
    int file_fd;

    close(pipe_fd[0]);
    file_fd = open(argv[1], O_RDONLY);
    if(file_fd == -1)
        ft_err();
    if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
        ft_err();
    if (dup2(file_fd, STDOUT_FILENO) == -1)
        ft_err();
    close(pipe_fd[1]);
    ex_cmd(argv[2], envp);
}

//Ejecuto el comando recibido en el arg
void ex_cmd(char *argv, char **envp)
{
    char **cmd_args;
    char *exe;
    char **procces_text;
    int i;
    
    i = 0;
    cmd_args = ft_split(argv, ' '); //tengo que hacer luego un free
    procces_text = get_path(envp);
    exe = procces_cmd(procces_text, argv);
    if (execve(exe, cmd_args, envp) == -1)
        ft_err();
    while (cmd_args[i] != NULL)
    {
        free (cmd_args);
        i++;
    }
}