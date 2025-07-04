/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:50:59 by chomobon          #+#    #+#             */
/*   Updated: 2023/10/04 16:12:13 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

int	ft_int_len(long x)
{
	int	i;

	i = 0;
	if (x < 0)
		x *= -1;
	while (x > 0)
	{
		x = x / 10;
		i++;
	}
	return (i);
}

void	ft_aux(int l, char *r, long d)
{
	if (d < 0)
	{
		d = -d;
		r[0] = '-';
	}
	while (d > 0)
	{
		r[--l] = d % 10 + '0';
		d = d / 10;
	}
}

char	*ft_itoa(int n)
{
	int			l;
	char		*r;
	long		d;

	d = (long)n;
	l = ft_int_len(d);
	if (d == 0)
		l = 1;
	if (d < 0)
		l++;
	r = (char *)malloc(sizeof(char) * l + 1);
	if (!r)
		return (NULL);
	ft_aux(l, r, d);
	if (d == 0)
		r[0] = '0';
	r[l] = '\0';
	return (r);
}
