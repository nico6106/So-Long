/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:45:52 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/08 18:09:01 by nlesage          ###   ########.fr       */
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
