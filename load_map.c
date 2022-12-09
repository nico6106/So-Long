/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 08:23:34 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/09 12:54:21 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_return_map(int argc, char **argv)
{
	t_list	*lst;
	char	**map;

	if (ft_check_argv(argc, argv) == 0)
	{
		ft_putstr_fd("Error\nYou need a .ber format.\n", 2);
		return (NULL);
	}
	lst = ft_extract_map(argv[1]);
	if (!lst)
		return (NULL);
	map = ft_assemble_map(lst);
	ft_lstclear(&lst);
	if (!map)
		return (NULL);
	if (ft_check_map(map) == 0)
	{
		ft_clear_map(map);
		return (NULL);
	}
	return (map);
}

char	**ft_assemble_map(t_list *lst)
{
	int		nb_row;
	int		i;
	int		nb_column;
	char	**map;

	nb_column = ft_verif_nb_char_per_row(lst);
	if (nb_column == 0)
		return (NULL);
	nb_row = ft_lstsize(lst);
	map = malloc((nb_row + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	map[nb_row] = 0;
	i = 0;
	while (lst)
	{
		map[i] = malloc((nb_column + 1) * sizeof(char));
		if (!map[i])
			return (ft_clear_map_after_error(map, i));
		ft_memcpy(map[i], lst->content, nb_column);
		map[i][nb_column] = 0;
		i++;
		lst = lst->next;
	}
	return (map);
}

int	ft_verif_nb_char_per_row(t_list *lst)
{
	size_t		nb_column;
	size_t		len;
	char		*str;

	str = (char *) lst->content;
	nb_column = ft_strlen((const char *) lst->content);
	if (str[nb_column - 1] == '\n')
			nb_column--;
	lst = lst->next;
	while (lst)
	{
		str = (char *) lst->content;
		len = ft_strlen((const char *) lst->content);
		if (str[len - 1] == '\n')
			len--;
		if (len != nb_column)
		{
			ft_putstr_fd("Error\nThe map is not a rectangle.\n", 2);
			return (0);
		}
		lst = lst->next;
	}
	return ((int) nb_column);
}

t_list	*ft_extract_map(char *map_name)
{
	int		fd;
	char	*row;
	t_list	*lst;

	lst = NULL;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nYour there is no map with this pathname.\n", 2);
		return (NULL);
	}
	row = get_next_line(fd);
	while (row)
	{
		if (ft_lst_create_elem_and_addback(&lst, row) == 0)
		{
			free(row);
			return (NULL);
		}
		row = get_next_line(fd);
	}
	close(fd);
	free(row);
	return (lst);
}

int	ft_check_argv(int argc, char **argv)
{
	int	len;

	len = 0;
	if (argc != 2)
		return (0);
	while (argv[1][len])
	{
		len++;
	}
	if (len <= 4)
		return (0);
	if (argv[1][len - 4] != '.')
		return (0);
	if (argv[1][len - 3] != 'b')
		return (0);
	if (argv[1][len - 2] != 'e')
		return (0);
	if (argv[1][len - 1] != 'r')
		return (0);
	return (1);
}
