/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_extract_text.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:19:47 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/01 14:40:13 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_add_txt_to_lst(t_list_p **lst, const char *s, int start)
{
	char	*data;
	int		i;

	i = start;
	while (s[i])
	{
		if (s[i] == '%')
		{
			data = ft_extract_text(s, start, i - 1);
			if (!data)
				return (-1);
			ft_add_elem_back_lst(lst, data, 1, 0);
			return (i - 1);
		}
		i++;
	}
	data = ft_extract_text(s, start, i);
	if (!data)
		return (-1);
	ft_add_elem_back_lst(lst, data, 1, 0);
	return (i - 1);
}

char	*ft_extract_text(const char *s, int start, int end)
{
	char	*data;
	int		i;

	i = 0;
	data = malloc((end - start + 1 + 1) * sizeof(char));
	if (!data)
		return (NULL);
	while (start <= end)
		data[i++] = s[start++];
	data[i] = '\0';
	return (data);
}

char	*ft_add_text_to_data(char *data, char *adding)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data[i])
		i++;
	while (adding[j])
		j++;
	new = malloc((i + j + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	j = -1;
	while (adding[++j])
		new[j] = adding[j];
	while (data[++i])
		new[i + j] = data[i];
	new[i + j] = '\0';
	free(data);
	return (new);
}
