/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:49:21 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/02 11:23:15 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear_pointeur(t_list **lst, void (*del)(void *))
{
	t_list	*next_chain;
	t_list	*begin;

	if (!lst | !(*del))
		return ;
	begin = *lst;
	while (*lst)
	{
		(*del)((*lst)->content);
		next_chain = (*lst)->next;
		free(*lst);
		*lst = next_chain;
	}
	*lst = begin;
	*lst = NULL;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*next_chain;
	t_list	*begin;

	if (!lst)
		return ;
	begin = *lst;
	while (*lst)
	{
		free((*lst)->content);
		next_chain = (*lst)->next;
		free(*lst);
		*lst = next_chain;
	}
	*lst = begin;
	*lst = NULL;
}
