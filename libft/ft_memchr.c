/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:10:07 by chomobon          #+#    #+#             */
/*   Updated: 2024/07/11 15:00:19 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	z;

	str = (unsigned char *)s;
	z = (unsigned char)c;
	i = 0;
	while (i < n && (str[i] != z))
		i++;
	if (i == n)
		return (NULL);
	return ((void *) &str[i]);
}

/*int main(void)
{
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	//char str[] = "Hello, World!";
    //int search_byte = 'W';
    //size_t n = 13;  // Número de bytes a buscar (tamaño del array)
	printf("%s", (char *)ft_memchr(tab, -1, 7));
	printf("%s", (char *)memchr(tab, -1, 7));
	//printf("Esto lo hace el mem %s\n", memchr(str, search_byte, n));
   //ft_memchr(str, search_byte, n); 
   //printf("Esto lo hace mi mem %s", ft_memchr(str, search_byte, n));
}*/
