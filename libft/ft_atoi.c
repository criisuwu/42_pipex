/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:16:34 by chomobon          #+#    #+#             */
/*   Updated: 2023/09/18 16:47:44 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	num;

	i = 0;
	neg = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57))
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (neg * num);
}

/*int	main(void)
{
	char	*a = "  	----+-1234ab435";

	printf("%d\n", ft_atoi(a));
}*/
