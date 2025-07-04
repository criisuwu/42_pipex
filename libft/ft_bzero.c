/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:28:33 by chomobon          #+#    #+#             */
/*   Updated: 2023/09/15 17:08:30 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_bzero(void *ptr, size_t num)
{
	unsigned char	*char_ptr;
	size_t			i;

	char_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		char_ptr[i] = 0;
		i++;
	}
	return (ptr);
}

/*int main(void) {
    char buffer[30];

    ft_bzero(buffer, sizeof(buffer));

    int i = 0;
    while (i < 30)
	{
        printf("%d ", buffer[i]);
        i++;
    }

    return 0;
}*/
