/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:50:38 by chomobon          #+#    #+#             */
/*   Updated: 2024/04/22 16:07:08 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdio.h>

/*char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]) != set)
	{
		i++;
	}
	return ((char *)&s1[i]);
}*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1) != 0)
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len - 1]) != 0)
		len--;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, len);
	res[len] = '\0';
	return (res);
}

/* int main()
{
	char *b = "hoJAlaJAJAaJAAAAAAAAAAAAJ";
	ft_strtrim(b, "JA");
	printf("%s\n", ft_strtrim(b, "JA"));
} */
