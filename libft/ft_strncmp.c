/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:49:23 by chomobon          #+#    #+#             */
/*   Updated: 2023/10/13 13:29:33 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] > s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else if (s1[i] < s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>
int main(void)
{
    char s1[]= "hona";
    char s2[]="hola";
    ft_strncmp(s1, s2, 2);
    printf("%d", ft_strncmp(s1, s2, 5));
    printf("\n");
    printf("%d", strncmp(s1, s2, 5));
}*/
