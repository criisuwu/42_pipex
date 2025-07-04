/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:01:52 by chomobon          #+#    #+#             */
/*   Updated: 2024/07/11 15:02:43 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t num)
{
	char	*ptr;
	size_t	i;

	if (count * num > SIZE_MAX)
		return (NULL);
	ptr = malloc(count * num);
	if (ptr != NULL)
	{
		i = 0;
		while (i < count * num)
		{
			ptr[i] = 0;
			i++;
		}
	}
	return (ptr);
}

/*int main(void) {
    char buffer[30];

    ft_bzero(buffer, sizeof(buffer));

    int i = 0;
    while (i < 30)
	{
        printf("%d\n", buffer[i]);
        i++;
    }
}*/
