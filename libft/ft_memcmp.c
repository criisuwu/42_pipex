/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:01:55 by chomobon          #+#    #+#             */
/*   Updated: 2023/09/25 17:47:21 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n && str1[i] == str2[i])
		i++;
	if (i == n)
	{
		return (0);
	}
	return ((int)str1[i] - (int)str2[i]);
}

/*int main(void)
{
	char str1[] = "Hello";
    char str2[] = "HELLO";
    size_t n = 5;
	printf ("el resultado es %d\n", ft_memcmp(str1, str2, n));
}*/
