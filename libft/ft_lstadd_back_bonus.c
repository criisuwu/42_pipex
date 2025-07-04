/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:41:00 by chomobon          #+#    #+#             */
/*   Updated: 2024/04/22 16:34:46 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*followingnode;

	if (!*lst)
	{
		if (!new)
			return ;
		*lst = new;
		return ;
	}
	followingnode = *lst;
	while (followingnode->next != NULL)
		followingnode = followingnode->next;
	followingnode->next = new;
}
