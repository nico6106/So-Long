/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_valid_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:20:03 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/09 10:50:37 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_verif_map_is_valid(char **map, int option)
{
	char	**copy;
	t_coord	start;
	t_map	map_cp;

	copy = ft_copy_map(map, 0, 0);
	if (!copy)
		return (1);
	map_cp = ft_create_struct_map(copy);
	map_cp.nb_items = 0;
	start = ft_extract_coord(map_cp.map, 'P');
	map_cp = ft_algo(map_cp, start);
	ft_clear_map(map_cp.map);
	if (map_cp.nb_items != (ft_count_items(map) + 2))
	{
		if (option == 1)
			ft_putstr_fd("Error\nYour map is not possible.\n", 2);
		return (1);
	}
	return (0);
}

t_map	ft_algo(t_map tp, t_coord start)
{
	t_coord	next;

	if (tp.map[start.y][start.x] == 'E')
	{
		tp.nb_items++;
		tp.map[start.y][start.x] = '5';
		return (tp);
	}
	if (tp.map[start.y][start.x] == 'P' || tp.map[start.y][start.x] == 'C')
		tp.nb_items++;
	tp.map[start.y][start.x] = '5';
	next = ft_return_next_coord(tp.map, start, 1);
	if (ft_is_in_charset(tp.map[next.y][next.x], "5") == 0)
		tp = ft_algo(tp, next);
	next = ft_return_next_coord(tp.map, start, 2);
	if (ft_is_in_charset(tp.map[next.y][next.x], "5") == 0)
		tp = ft_algo(tp, next);
	next = ft_return_next_coord(tp.map, start, 3);
	if (ft_is_in_charset(tp.map[next.y][next.x], "5") == 0)
		tp = ft_algo(tp, next);
	next = ft_return_next_coord(tp.map, start, 4);
	if (ft_is_in_charset(tp.map[next.y][next.x], "5") == 0)
		tp = ft_algo(tp, next);
	return (tp);
}

t_coord	ft_return_next_coord(char **map, t_coord start, int dir)
{
	t_coord	next;

	next.x = -1;
	next.y = -1;
	if (dir == 1 && start.y > 0)
	{
		next.y = start.y - 1;
		next.x = start.x;
	}
	else if (dir == 2 && start.x > 0)
	{
		next.y = start.y;
		next.x = start.x - 1;
	}
	else if (dir == 3 && start.x < ((int) ft_strlen(map[0]) - 1))
	{
		next.y = start.y;
		next.x = start.x + 1;
	}
	if (dir == 4 && start.y < (ft_count_nb_row_in_tab(map) - 1))
	{
		next.y = start.y + 1;
		next.x = start.x;
	}
	return (next);
}

t_coord	ft_extract_coord(char **map, char c)
{
	t_coord	coord;
	int		i;
	int		j;

	i = 0;
	coord.x = 0;
	coord.y = 0;
	coord.c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				coord.x = j;
				coord.y = i;
				coord.c = c;
				return (coord);
			}
			j++;
		}
		i++;
	}
	return (coord);
}
