/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:26:06 by chomobon          #+#    #+#             */
/*   Updated: 2024/04/22 16:06:50 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	listsize;
	size_t	i;

	i = 0;
	listsize = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c)
			|| (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c))
			listsize++;
		i++;
	}
	return (listsize);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char			*buffer;
	unsigned int	i;

	i = 0;
	if (ft_strlen(s) <= n)
		n = ft_strlen(s);
	buffer = malloc(sizeof(char) * (n + 1));
	if (buffer == NULL)
		return (NULL);
	while (i < n)
	{
		buffer[i] = s[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

static char	**ft_freeall(char **list)
{
	size_t	j;

	j = 0;
	while (list[j])
	{
		free(list[j]);
		j++;
	}
	free(list);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strlist;
	size_t	i;
	size_t	k;
	size_t	save;

	i = 0;
	k = 0;
	strlist = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!strlist)
		return (NULL);
	while (i < ft_wordcount(s, c) && s[k] != '\0')
	{
		while (s[k] == c)
			k++;
		save = k;
		while (s[k] != c && s[k] != '\0')
			k++;
		strlist[i] = ft_strndup(&s[save], k - save);
		if (strlist[i++] == 0)
			return (ft_freeall(strlist));
	}
	strlist[i] = NULL;
	return (strlist);
}

/* int	main()
{
	const char	*s = "      Esta es una frase de prueba       ";
	char		c = 's';
	int 		i = 0;
	char		**rebp;
	
	rebp = ft_split(s, c);
	while (rebp[i] != NULL)
	{
		printf("%s\n", rebp[i]);
		i++;
	}
} */