/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:51:55 by nlesage           #+#    #+#             */
/*   Updated: 2022/11/12 10:28:38 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;
	void	*data_elem;

	new_list = NULL;
	if (!lst | !(*f) | !(*del))
		return (NULL);
	while (lst)
	{
		data_elem = (*f)(lst->content);
		new_elem = ft_lstnew(data_elem);
		if (!new_elem)
		{
			return (NULL);
		}
		else
			ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}
