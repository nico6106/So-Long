/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:15:33 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/02 11:24:53 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_create_and_lstadd_back(t_list **lst, void *data)
{
	t_list	*begin_list;
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (!new_elem)
		return ;
	new_elem->content = data;
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
