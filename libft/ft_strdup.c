/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:47:57 by chomobon          #+#    #+#             */
/*   Updated: 2024/07/11 15:03:35 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s1)
{
	char	*d;
	size_t	l;
	size_t	i;

	i = 0;
	l = ft_strlen(s1);
	d = malloc(l + 1);
	if (!d)
		return (NULL);
	while (i < l && s1[i])
	{
		d[i] = s1[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
