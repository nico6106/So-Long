/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ft_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:19:06 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/02 08:59:12 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	t_list_p	*lst;
	t_list_p	*begin;
	va_list		params;
	int			check;
	int			nb_char;

	if (!s)
		return (0);
	lst = ft_extract_data_from_s(s);
	if (!lst)
		return (ft_lstclear_printf(&lst));
	va_start(params, s);
	check = ft_comp_lst_wih_arg(&lst, params, 1, lst);
	va_end(params);
	if (check == 0)
		return (ft_lstclear_printf(&lst));
	begin = lst;
	nb_char = 0;
	while (lst)
	{
		nb_char = nb_char + ft_show_elem(lst, 0);
		lst = lst->next;
	}
	ft_lstclear_printf(&begin);
	return (nb_char);
}

int	ft_comp_lst_wih_arg(t_list_p **lst, va_list params, int a, t_list_p *b)
{
	while (*lst)
	{
		if ((*lst)->type == 3)
			a = ft_handle_char(lst, va_arg(params, int));
		if ((*lst)->type == 4)
			a = ft_handle_string(lst, va_arg(params, char *));
		if ((*lst)->type == 2)
			a = ft_handle_nb_base10(lst, va_arg(params, int));
		if ((*lst)->type == 6)
			a = ft_handle_nb_u_base10(lst, va_arg(params, unsigned int));
		if ((*lst)->type == 5)
			a = ft_handl_add(lst, (unsigned long long) va_arg(params, void *));
		if ((*lst)->type == 7)
			a = ft_handle_nb16(lst, 1, va_arg(params, unsigned long int));
		if ((*lst)->type == 8)
			a = ft_handle_nb16(lst, 2, va_arg(params, unsigned long int));
		a = ft_final_treatment(lst);
		(*lst) = (*lst)->next;
		if (a == 0)
			return (0);
	}
	(*lst) = b;
	return (1);
}

int	ft_handle_nb16(t_list_p **lst, int op_base, unsigned long int nb)
{
	char		*data;

	if (!lst)
		return (0);
	if (op_base == 1)
		data = ft_return_nb_base_int("0123456789abcdef", nb, 0);
	else
		data = ft_return_nb_base_int("0123456789ABCDEF", nb, 0);
	if (!data)
		return (0);
	data = ft_reverse_string(data);
	if (data[0] == '0' && data[1] == '\0')
		(*lst)->flag = 0;
	if ((*lst)->flag == 3 && nb > 0 && op_base == 1)
		data = ft_add_text_to_data(data, "0x");
	if ((*lst)->flag == 3 && nb > 0 && op_base == 2)
		data = ft_add_text_to_data(data, "0X");
	if (!data)
		return (0);
	(*lst)->content = data;
	(*lst)->type = 1;
	return (1);
}

char	*ft_return_nb_base(char *base, unsigned long int nb, int position)
{
	unsigned long int	mod_bis;
	char				*data;

	if (nb < 16)
		mod_bis = nb;
	else
	{
		mod_bis = nb % 16;
		data = ft_return_nb_base(base, nb / 16, position + 1);
	}
	if (nb < 16)
	{
		data = malloc((position + 1 + 1) * sizeof(char));
		data[position + 1] = '\0';
	}
	if (!data)
		return (NULL);
	data[position] = base[mod_bis % 16];
	return (data);
}

char	*ft_return_nb_base_int(char *base, unsigned int nb, int position)
{
	unsigned int	mod_bis;
	char			*data;

	if (nb < 16)
		mod_bis = nb;
	else
	{
		mod_bis = nb % 16;
		data = ft_return_nb_base(base, nb / 16, position + 1);
	}
	if (nb < 16)
	{
		data = malloc((position + 1 + 1) * sizeof(char));
		data[position + 1] = '\0';
	}
	if (!data)
		return (NULL);
	data[position] = base[mod_bis % 16];
	return (data);
}
