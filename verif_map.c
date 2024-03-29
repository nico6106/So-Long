/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 08:47:04 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/09 15:19:39 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map(char **map)
{
	int	error;

	error = 0;
	error = error + ft_check_walls(map);
	if (error != 0)
		return (0);
	error = error + ft_check_element_map(map);
	error = error + ft_check_items(map, 0, 0, 0);
	if (error != 0)
		return (0);
	error = error + ft_verif_map_is_valid(map, 1);
	if (error != 0)
		return (0);
	return (1);
}

int	ft_check_walls(char **map)
{
	int	error;
	int	i;

	i = 0;
	error = ft_check_wall(map[0], 1);
	while (map[++i])
	{
		error = error + ft_check_wall(map[i], 2);
	}
	error = error + ft_check_wall(map[i - 1], 1);
	if (error != 0)
		ft_putstr_fd("Error\nThere is a problem with your walls.\n", 2);
	return (error);
}

int	ft_check_items(char **map, int i_start, int i_end, int i_tocollect)
{
	int	i;
	int	j;
	int	error;

	i = 0;
	error = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
				i_end++;
			if (map[i][j] == 'C')
				i_tocollect++;
			if (map[i][j] == 'P')
				i_start++;
		}
	}
	if (i_start != 1 || i_end != 1 || i_tocollect == 0)
		error++;
	if (error != 0)
		ft_putstr_fd("Error\nThere is a problem with at least one item\n", 2);
	return (error);
}

int	ft_check_wall(char *row, int option)
{
	int	i;

	i = -1;
	if (option == 1)
	{
		while (row[++i])
		{
			if (row[i] != '1')
				return (1);
		}
		return (0);
	}
	else if (option == 2)
	{
		if (row[0] != '1' || row[ft_strlen(row) - 1] != '1')
			return (1);
		return (0);
	}
	return (1);
}

int	ft_check_element_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_is_in_charset(map[i][j], "01EPC") == 0)
			{
				ft_putstr_fd("Error\nThere is a wrong entry\n", 2);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
