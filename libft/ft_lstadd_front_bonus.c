/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:03:18 by chomobon          #+#    #+#             */
/*   Updated: 2024/04/22 16:02:18 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Mientras existan ambos nodos va a añadir un nodo al principio
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
