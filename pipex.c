/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:39:30 by codespace         #+#    #+#             */
/*   Updated: 2025/07/04 18:51:19 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include "libft/libft.h"


//Aqui tengo que gestioanar el path, el abrir el archivo y ejecutar el archivo
void procces_cmd(char *argv, char **envp)
{
    char **path;
    char **c_path;
    char *cmd;
    char *join_path;
    int l_path;
    int i;
    
    i = 0;
    while (envp[i] != NULL)
    {
        if (ft_strncmp("PATH", envp[i], 6))
        {
            l_path = ft_strdup(envp[i]); //Free despues
            break;
        }
        i++;
    }
    c_path = ft_split(l_path, '=');
    path = ft_split(c_path[1], ':');
    i = 0;
    while (path[i] != NULL)
    {
        cmd = ft_strjoin(path[i], '/');
        join_path = ft_strjoin(cmd, argv);
        //Compruebo si existe
        // ! si  no existe libero y paso a la siguiente linea
        // ? si existe paro y lo devuelvo :)
    }
    open();
    
}

int main(int argc, char **argv, char **envp)
{
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
    {;
        close(pipe_fd[0]); //to look
        dup2(pipe_fd[0], STDOUT_FILENO); //to look
        //close(pipe_fd[1]);
        //Procesamos los argumentos que recibe. Es decir hacemos de primeras un split.
        procces_args(argv[1], envp);
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
        procces_args(argv[1], envp);
        exit(1);
    }
    
    // pid = fork();
    // if (pid == -1)
    // {
    //     perror("Error en el fork\n");
    //     return(1);
    // }
    // if (pid == 0)
    // {
    //     printf("hell");
    //     close(pipe_fd[0]);
    //     dup2(pipe_fd[1], STDOUT_FILENO);
    //     close(pipe_fd[1]);
    //     printf("antes de procesar los argumentos");
    //     //Procesamos los argumentos que recibe. Es decir hacemos de primeras un split.
    //     procces_args(*argv, envp);
    //     exit(1);
    // }
    // return (0);
}