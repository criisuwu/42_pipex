/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:57:23 by chomobon          #+#    #+#             */
/*   Updated: 2024/04/22 15:13:54 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned long	i;
	unsigned long	l;
	char			*str;

	l = ft_strlen(s);
	str = (char *) malloc(sizeof(char) * (l + 1));
	if (str == 0)
		return (str);
	i = 0;
	while (i < l)
	{
		str[i] = (*f)(i, s[i]);
		++i;
	}
	str[i] = 0;
	return (str);
}
