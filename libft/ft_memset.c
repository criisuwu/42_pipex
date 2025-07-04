/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:47:44 by chomobon          #+#    #+#             */
/*   Updated: 2023/09/15 17:04:10 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*char_ptr;
	size_t			i;

	char_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		char_ptr[i] = (unsigned char)(value);
		i++;
	}
	return (ptr);
}

/*int main() {
    char buffer[15];

    ft_memset(buffer, 2, sizeof(buffer));

    int i = 0;
    while (i < 15)
	{
        printf("%d\n", buffer[i]);
        i++;
    }

    return 0;
}*/
