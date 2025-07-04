/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:38:23 by chomobon          #+#    #+#             */
/*   Updated: 2023/09/29 17:36:01 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	i;
	char			nl;

	i = 0;
	nl = '\n';
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			write(fd, &nl, 1);
		else if (s[i] == '\0')
			break ;
		else
			write(fd, &s[i], sizeof(char));
		i++;
	}
	write(fd, &nl, 1);
}
