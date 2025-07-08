/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:53:54 by chomobon          #+#    #+#             */
/*   Updated: 2025/07/08 17:57:57 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include "libft/libft.h"

char **get_path(char **envp);
char *procces_cmd(char **procces_text, char *argv);

#endif