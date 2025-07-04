/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:49:16 by chomobon          #+#    #+#             */
/*   Updated: 2023/09/21 18:30:55 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s != '\0')
	{
		if (*s == (char)(c))
			last = s;
		s++;
	}
	if (*s == (char)c)
		last = s;
	return ((char *)last);
}
/*
int main(void)
{
	const char *str = "Hola, mundo!";
    int search_character = '\0';

    char *result = ft_strrchr(str, search_character);
	printf ("esto lo hace e strrchr %s\n", strrchr(str, search_character));
	printf("esto lo hace mi ft %s\n", ft_strrchr(str, search_character));
}*/
