/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:05:58 by chomobon          #+#    #+#             */
/*   Updated: 2023/09/25 16:57:13 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)(dst);
	s = (unsigned char *)(src);
	i = 0;
	if (d < s && (dst != NULL || src != NULL))
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (s < d && (dst != NULL || src != NULL))
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
	return (d);
}

/*int main(void)
{
 char str1[50] = "Hola";
  char str2[50] = "Hola";

  Copiamos el contenido de str1 a str2,
  incluso si las áreas de memoria se superponen.
  ft_memmove(str1 + 2, str1, 20);

  Imprimimos el contenido de str2.
  printf("%s\n", str1);
	memmove(str2 + 2, str2, 20);	
  printf("La funcion memmove nos devuelve: %s", str2);
}
int main(void)
{
	char	src[] = "123456789";
	char	src2[] = "123456789";
	char	*dest;
	char	*dest2;

	dest = src + 1;
	dest2 = src2 + 1;

	memmove(src, dest, 4);
	// write(1, dest, 10);
	printf("Dest memmove: %s\n", dest);
	
	ft_memmove(src2, dest2, 4);
	// write(1, dest2, 10);
	printf("Dest ft_move: %s\n", dest2);
	return (0);
}
int main()
{
	char *s1 = "atoms\0\0\0\0";
 	char *s2 = "atoms\0abc";
	size_t size = 8;
	int i1 = simple_memcmp(s1, s2, size);
 	int i2 = ft_memcmp(s1, s2, size);
	pritnf ("%s\n", simple_memmove(s1, s2, 7));
	printf ("%s\n", ft_memmove(s1, s2, 7));
}*/
