/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:26:12 by chomobon          #+#    #+#             */
/*   Updated: 2024/07/11 15:58:20 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*aux;
	void	*new_cont;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst && f)
	{
		new_cont = f(lst->content);
		aux = ft_lstnew(new_cont);
		if (!aux)
		{
			if (del && new_cont)
				del(new_cont);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, aux);
		lst = lst->next;
	}
	return (new_list);
}
