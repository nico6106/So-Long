/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_initial_analysis.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:49:28 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/02 08:55:24 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list_p	*ft_extract_data_from_s(const char *s)
{
	t_list_p	*lst;
	t_position	p;

	lst = NULL;
	p.start = 0;
	p.end = 0;
	p.chaine = s;
	while (s[p.start])
	{
		if (s[p.start] == '%')
		{
			p.start = ft_add_flag_to_lst(&lst, p, 0, p.start + 1);
			if (p.start == 0)
				return (NULL);
		}
		else
		{
			p.start = ft_add_txt_to_lst(&lst, p.chaine, p.start);
			if (p.start == -1)
				return (NULL);
		}
		p.start++;
	}
	return (lst);
}

int	ft_add_flag_to_lst(t_list_p **lst, t_position p, int check, int i)
{
	char	*data;

	while (p.chaine[i])
	{
		if (p.chaine[i] == '%' && i == p.start + 1)
		{
			data = ft_extract_text(p.chaine, i, i);
			ft_add_elem_back_lst(lst, data, 1, 0);
			return (i);
		}
		check = ft_is_in_charset(p.chaine[i], "cspdiuxX");
		if (check == 1)
		{
			p.end = i;
			ft_add_elem_back_lst(lst, NULL, 0, 0);
			check = ft_check_and_treat_flag(lst, p);
			if (check == 0)
				return (ft_lstclear_printf(lst));
			return (i);
		}
		if (check == 0 && ft_isalpha(p.chaine[i]) == 1)
			return (ft_lstclear_printf(lst));
		i++;
	}
	return (ft_lstclear_printf(lst));
}

int	ft_check_and_treat_flag(t_list_p **lst, t_position p)
{
	t_list_p	*begin;

	begin = (*lst);
	if (!lst)
		return (0);
	while ((*lst)->next)
		(*lst) = (*lst)->next;
	(*lst)->type = ft_add_type(p);
	(*lst)->flag = ft_add_flag(p);
	(*lst)->flag2 = ft_add_other_flag(lst, p);
	(*lst) = begin;
	return (1);
}

int	ft_is_in_charset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_add_type(t_position p)
{
	if (p.chaine[p.end] == 'c')
		return (3);
	if (p.chaine[p.end] == 's')
		return (4);
	if (p.chaine[p.end] == 'p')
		return (5);
	if (p.chaine[p.end] == 'd')
		return (2);
	if (p.chaine[p.end] == 'i')
		return (2);
	if (p.chaine[p.end] == 'u')
		return (6);
	if (p.chaine[p.end] == 'x')
		return (7);
	if (p.chaine[p.end] == 'X')
		return (8);
	return (0);
}
