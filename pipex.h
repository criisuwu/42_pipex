/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:53:54 by chomobon          #+#    #+#             */
/*   Updated: 2025/07/11 13:32:15 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

char	**get_path(char **envp);
char	*procces_cmd(char **procces_text, char *argv);
void	ex_cmd(char *argv, char **envp);
void	child_proc(int *pipe_fd, char **argv, char **envp);
void	parent_proc(int *pipe_fd, char **argv, char **envp);
void	ft_err(void);

#endif