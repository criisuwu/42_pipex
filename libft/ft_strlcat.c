/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:00:36 by chomobon          #+#    #+#             */
/*   Updated: 2023/09/21 18:00:46 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t nb)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (nb == 0 && (!src || !dest))
	{
		return (0);
	}
	while (dest[i] != '\0' && i < nb)
	{
		i++;
	}
	while (src[j] != '\0' && nb > (i + j + 1))
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < nb)
	{
		dest[i + j] = '\0';
	}
	return (i + ft_strlen(src));
}

/*int	main(void)
{
	char result[28] = "Pepe 4 ever";
	char *p = "holis";
	printf("%s", ft_strlcat(result, p, 5));
}*/
