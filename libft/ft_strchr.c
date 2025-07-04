/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:20:09 by chomobon          #+#    #+#             */
/*   Updated: 2023/09/18 18:47:09 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
	{
		s++;
	}
	if (*s == (char)c)
	{
		return ((char *)(s));
	}
	return (NULL);
}

/*int main(void)
{
	const char *str = "Hola, mundo!";
    int search_character = 'm';

    char *result = ft_strchr(str, search_character);
	printf("%s\n", ft_strchr(str, search_character));
}*/
