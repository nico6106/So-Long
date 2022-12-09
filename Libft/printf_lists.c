/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:18:30 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/09 11:19:30 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_add_elem_back_lst(t_list_p **lst, void *data, int type, int flag)
{
	t_list_p	*begin_list;
	t_list_p	*new_elem;

	new_elem = malloc(sizeof(t_list_p));
	if (!new_elem)
		return ;
	new_elem->content = data;
	new_elem->type = type;
	new_elem->flag = flag;
	new_elem->flag2 = 0;
	new_elem->width = 0;
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

int	ft_lstclear_printf(t_list_p **lst)
{
	t_list_p	*next_chain;
	t_list_p	*begin;

	if (!lst)
		return (0);
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
	return (0);
}

char	*ft_reverse_string(char *s)
{
	int		len;
	int		i;
	char	c;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	while (i < len / 2)
	{
		c = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = c;
		i++;
	}
	return (s);
}

char	*ft_return_data_from_text(char *text)
{
	char	*data;
	int		i;

	i = 0;
	if (!text)
		return (NULL);
	while (text[i])
		i++;
	data = malloc((i + 1) * sizeof(char));
	if (!data)
		return (NULL);
	data[i] = '\0';
	i = 0;
	while (text[i])
	{
		data[i] = text[i];
		i++;
	}
	data[i] = '\0';
	return (data);
}

char	*ft_to_next_number(char *data, char c)
{
	int	i;

	i = 0;
	while (data[i])
	{
		if (data[i] >= '0' && data[i] <= '9')
		{
			if (i > 0)
				data[i - 1] = c;
			return (data);
		}
		i++;
	}
	return (data);
}
