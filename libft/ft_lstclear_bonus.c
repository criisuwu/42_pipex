/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:11:13 by chomobon          #+#    #+#             */
/*   Updated: 2024/04/26 14:28:28 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	aux = *lst;
	while (aux)
	{
		del(aux->content);
		*lst = aux->next;
		free(aux);
		aux = *lst;
	}
	*lst = NULL;
}
