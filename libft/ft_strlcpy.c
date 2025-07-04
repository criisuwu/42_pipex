/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:48:34 by chomobon          #+#    #+#             */
/*   Updated: 2023/09/19 18:18:27 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	if (!n)
	{
		return (ft_strlen(src));
	}
	i = 0;
	while (src[i] && (i < n - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (ft_strlen(src));
}
/*int	main(void)
{
	char result[28] = "Pepe 4 ever";
	char *p = "holis";
	printf("%s", ft_strlcpy(result, p, 1));
}*/
