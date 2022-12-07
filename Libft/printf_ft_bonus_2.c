/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ft_bonus_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:32:31 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/01 14:28:44 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_show_elem(t_list_p *lst, int i)
{
	char	*data;

	data = (char *) lst->content;
	if (lst->type == 3 && data[0] == 0)
	{
		write(1, "\0", 1);
		return (1);
	}
	if (lst->flag == -3)
	{
		write(1, "\0", 1);
		i++;
	}
	while (data[i])
	{
		write(1, &data[i], 1);
		i++;
	}
	if (lst->flag == -2)
	{
		write(1, "\0", 1);
		i++;
	}
	return (i);
}

int	ft_handle_sign_in_data(t_list_p **lst, char **data_p, char c, int len)
{
	int		to_add_last;
	char	*data;

	if (!data_p)
		return (0);
	data = *data_p;
	to_add_last = 0;
	if (data[0] == '\0' && (*lst)->width > 0 && (*lst)->type == 3)
		(*lst)->flag = -2;
	if ((data[0] == '+' || data[0] == '-') && len < (*lst)->width && c == '0')
	{
		to_add_last = data[0];
		data[0] = c;
	}
	if ((data[0] == '+' || data[0] == '-') && len < (*lst)->width && c == ' ')
	{
		to_add_last = -data[0];
		data[0] = c;
	}
	return (to_add_last);
}

char	*ft_return_tab_amended(t_list_p **lst, char *data, int to_add_last)
{
	if (!data)
		return (NULL);
	if (to_add_last < 0)
		data = ft_to_next_number(data, -to_add_last);
	if (to_add_last > 0)
		data[0] = to_add_last;
	if ((*lst)->flag == -2)
			data[(*lst)->width - 1] = '\0';
	return (data);
}
