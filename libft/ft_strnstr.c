/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:08:06 by chomobon          #+#    #+#             */
/*   Updated: 2023/10/09 18:19:25 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	size;

	size = 0;
	if (*s2 == '\0')
	{
		return ((char *)(s1));
	}
	while (s2[size] != '\0')
	{
		++size;
	}
	while (*s1 != '\0' && n >= size)
	{
		if (*s1 == *s2 && ft_strncmp(s1, s2, size) == 0)
		{
			return ((char *)(s1));
		}
		++s1;
		--n;
	}
	return (NULL);
}

/*int main(void)
{
	const char *h = "Pepito Grillo";
	const char *n = "Grillo";
	size_t l = 20;

	char *result;
	result = ft_strnstr(h, n, l);
	printf("Esto lo hace el strnstr %s\n", strnstr(h, n, l));
	printf("Esto lo hace mi funcion %s\n", ft_strnstr(h, n, l));
}*/
