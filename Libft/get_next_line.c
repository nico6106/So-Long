/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:53:04 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/02 14:56:29 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*row;
	t_list		*chaine;
	int			nb_char;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	chaine = NULL;
	nb_char = ft_read_row_givelst(fd, 0, &chaine, 0);
	if (nb_char == 0)
	{
		ft_lstclear(&chaine);
		return (NULL);
	}
	row = ft_create_row(chaine, nb_char);
	ft_lstclear(&chaine);
	return (row);
}

int	ft_read_row_givelst(int fd, int size, t_list **chaine, int nb_char)
{
	static char		buf[BUFFER_SIZE + 1];
	t_position_g	position;
	char			*data;

	buf[BUFFER_SIZE] = '\0';
	if (buf[0] == 0)
		size = read(fd, buf, BUFFER_SIZE);
	else
	{
		while (buf[size])
			size++;
	}
	while (size && size != -1)
	{
		position = ft_return_position(buf, size);
		data = ft_extract_data_from_buffer(position, buf, 0);
		if (position.end == -1 || position.start == -1 || !data)
			return (0);
		ft_create_and_lstadd_back(chaine, data);
		nb_char = nb_char + (position.end - position.start + 1);
		if (position.is_end == -1)
			break ;
		size = read(fd, buf, BUFFER_SIZE);
	}
	return (nb_char);
}

t_position_g	ft_return_position(char *buf, int size)
{
	t_position_g	position;
	int				i;

	position.start = 0;
	position.end = -1;
	position.is_end = 1;
	i = 0;
	while (i < size)
	{
		if (buf[i] == '\n' && position.end == -1)
		{
			position.is_end = -1;
			position.end = i;
		}
		i++;
		if (i == size && position.end == -1)
			position.end = i - 1;
	}
	return (position);
}

char	*ft_extract_data_from_buffer(t_position_g position, char *buf, int i)
{
	char	*data;

	data = malloc((position.end - position.start + 1 + 1) * sizeof(char));
	if (!data)
		return (NULL);
	data[position.end - position.start + 1] = '\0';
	while (position.start < BUFFER_SIZE && position.start <= position.end)
	{
		data[i] = buf[position.start];
		buf[position.start] = 0;
		i++;
		position.start++;
	}
	data[i] = 0;
	if (position.is_end == -1)
	{
		position.is_end = 0;
		while (position.start < BUFFER_SIZE && buf[position.start])
		{
			buf[position.is_end++] = buf[position.start];
			buf[position.start++] = 0;
		}
		buf[position.is_end] = '\0';
	}
	return (data);
}

char	*ft_create_row(t_list *lst, int nb_char)
{
	int		i;
	int		k;
	char	*data;
	char	*row;

	row = malloc((nb_char + 1) * sizeof(char));
	if (!row)
		return (NULL);
	row[nb_char] = '\0';
	i = 0;
	while (lst)
	{
		k = 0;
		data = (char *) lst->content;
		while (data[k])
			row[i++] = data[k++];
		lst = lst->next;
	}
	row[nb_char] = '\0';
	return (row);
}
