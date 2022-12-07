/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:45:52 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/03 15:57:47 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_lst_create_elem_and_addback(t_list **lst, void *data)
{
	t_list	*elem;

	elem = ft_lstnew(data);
	if (!elem)
	{
		ft_lstclear(lst);
		return (0);
	}
	ft_lstadd_back(lst, elem);
	return (1);
}

/*
int	ft_lst_coord_create_and_addback(t_list_coord **lst, t_coord coord)
{
	t_list_coord	*begin_list;
	t_list_coord	*new_elem;

	new_elem = malloc(sizeof(t_list_coord));
	if (!new_elem)
		return ;
	new_elem->content = coord;
	new_elem->next = NULL;
	begin_list = *lst;
	if (!(*lst))
		(*lst) = new_elem;
	else
	{
		while ((*lst)->next != NULL)
			*lst = (*lst)->next;
		(*lst)->next = new_elem;
		*lst = begin_list;
	}
}
*/