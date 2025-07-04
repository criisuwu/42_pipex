/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:42:18 by chomobon          #+#    #+#             */
/*   Updated: 2023/09/25 16:22:49 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = (char *)(dst);
	s = (const char *)(src);
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

/*int main() {
    char orig[20] = "Hola, mundo!";
    char dest[20] = "adios"; 

    ft_memcpy(orig +  1, orig, strlen(orig) + 1);

    printf("Contenido de destino: %s\n", orig);

    return (0);
}*/
