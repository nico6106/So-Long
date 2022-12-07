/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ft_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:12:54 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/02 09:01:33 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_add_flag(t_position p)
{
	int	i;

	i = p.start;
	while (p.chaine[i] && i <= p.end)
	{
		if (p.chaine[i] == '#')
			return (3);
		if (p.chaine[i] == '+')
			return (2);
		if (p.chaine[i] == ' ')
			return (6);
		i++;
	}
	return (0);
}

int	ft_add_other_flag(t_list_p **lst, t_position p)
{
	while (p.chaine[p.start] && p.start <= p.end)
	{
		if (p.chaine[p.start] == '-')
		{
			(*lst)->width = ft_abs(ft_atoi(&p.chaine[p.start + 1]));
			return (1);
		}
		if (p.chaine[p.start] == '0')
		{
			(*lst)->width = ft_atoi(&p.chaine[p.start + 1]);
			return (4);
		}
		if (p.chaine[p.start] >= '1' && p.chaine[p.start] <= '9')
		{
			(*lst)->width = ft_atoi(&p.chaine[p.start]);
			return (7);
		}
		p.start++;
	}
	return (0);
}

int	ft_final_treatment(t_list_p **lst)
{
	int	a;

	a = 1;
	if ((*lst)->flag2 == 1)
		a = ft_data_align_left(lst, (*lst)->content, ' ');
	else if ((*lst)->flag2 == 4 && ((*lst)->type == 3 || (*lst)->type == 4))
		a = ft_data_align_right(lst, (*lst)->content, ' ', 0);
	else if ((*lst)->flag2 == 4)
		a = ft_data_align_right(lst, (*lst)->content, '0', 0);
	else if ((*lst)->flag2 == 7)
		a = ft_data_align_right(lst, (*lst)->content, ' ', 0);
	if (a == 0)
		return (0);
	return (1);
}

int	ft_data_align_left(t_list_p **lst, char *data, char c)
{
	int		i;
	char	*new;

	i = 0;
	if (data[0] == '\0' && (*lst)->width > 0 && (*lst)->type == 3)
		(*lst)->flag = -3;
	while (data[i])
		i++;
	if (i < (*lst)->width)
	{
		i = -1;
		new = malloc(((*lst)->width + 1) * sizeof(char));
		if (!new)
			return (0);
		while (data[++i])
			new[i] = data[i];
		while (i < (*lst)->width)
			new[i++] = c;
		new[(*lst)->width] = '\0';
		free(data);
		(*lst)->content = new;
	}
	return (1);
}

int	ft_data_align_right(t_list_p **lst, char *data, char c, int len)
{
	int		i;
	int		k;
	int		to_add_last;
	char	*new;

	i = 0;
	k = 0;
	while (data[len])
		len++;
	to_add_last = ft_handle_sign_in_data(lst, &data, c, len);
	if (len < (*lst)->width)
	{
		new = malloc(((*lst)->width + 1) * sizeof(char));
		if (!new)
			return (0);
		while (i < ((*lst)->width - len))
			new[i++] = c;
		while (i < (*lst)->width)
			new[i++] = data[k++];
		new = ft_return_tab_amended(lst, new, to_add_last);
		new[(*lst)->width] = '\0';
		free(data);
		(*lst)->content = new;
	}
	return (1);
}
