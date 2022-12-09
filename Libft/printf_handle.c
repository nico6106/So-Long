/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:47:37 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/01 14:28:40 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_string(t_list_p **lst, char *arg)
{
	char	*data;
	int		i;

	if (!lst)
		return (0);
	if (!arg)
		data = ft_return_data_from_text("(null)");
	else
	{
		i = 0;
		while (arg[i])
			i++;
		data = malloc((i + 1) * sizeof(char));
		if (!data)
			return (0);
		data[i] = '\0';
		i = -1;
		while (arg[++i])
			data[i] = arg[i];
	}
	(*lst)->content = data;
	(*lst)->type = 1;
	return (1);
}

int	ft_handl_add(t_list_p **lst, unsigned long long address)
{
	char	*data;

	if (!lst)
		return (0);
	if (address == 0)
		data = ft_return_data_from_text("(nil)");
	else
	{
		data = ft_return_nb_base("0123456789abcdef", address, 0);
		if (!data)
			return (0);
		data = ft_reverse_string(data);
		data = ft_add_text_to_data(data, "0x");
	}
	if (!data)
		return (0);
	(*lst)->content = data;
	return (1);
}

int	ft_handle_char(t_list_p **lst, char c)
{
	char	*data;

	if (!lst)
		return (0);
	data = malloc(2 * sizeof(char));
	if (!data)
		return (0);
	data[0] = c;
	data[1] = '\0';
	(*lst)->content = data;
	return (1);
}

int	ft_handle_nb_u_base10(t_list_p **lst, long nb)
{
	char	*data;

	data = ft_itoa_unsigned((unsigned int) nb);
	if (!data)
		return (0);
	(*lst)->content = data;
	return (1);
}

int	ft_handle_nb_base10(t_list_p **lst, long nb)
{
	char	*data;

	data = ft_itoa(nb);
	if (!data)
		return (0);
	if ((*lst)->flag == 2 && nb >= 0)
		data = ft_add_text_to_data(data, "+");
	if ((*lst)->flag == 6 && nb >= 0)
		data = ft_add_text_to_data(data, " ");
	if (!data)
		return (0);
	(*lst)->content = data;
	return (1);
}
