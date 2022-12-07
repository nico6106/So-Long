/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_struct_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:30:24 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/07 13:47:43 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	ft_create_struct_map(char **map_load)
{
	t_map	struct_map;

	struct_map.map = map_load;
	struct_map.nb_column = (int) ft_strlen(map_load[0]);
	struct_map.nb_row = ft_count_nb_row_in_tab(map_load);
	struct_map.nb_items = ft_count_items(map_load);
	return (struct_map);
}

char	**ft_copy_map(char **map, int i, int j)
{
	char	**copy;

	while (map[i])
		i++;
	copy = malloc((i + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	copy[i] = 0;
	i = -1;
	while (map[++i])
	{
		copy[i] = malloc((ft_strlen(map[i]) + 1) * sizeof(char));
		if (!copy[i])
			return (ft_clear_map_after_error(copy, i));
		j = -1;
		while (map[i][++j])
		{
			copy[i][j] = map[i][j];
			if (map[i][j] == '1')
				copy[i][j] = '5';
		}
		copy[i][j] = 0;
	}
	copy[i] = 0;
	return (copy);
}

int	ft_count_nb_row_in_tab(char **map)
{
	int	i;

	if (!map)
		return (0);
	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	ft_count_items(char **map)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	nb = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				nb++;
			j++;
		}
		i++;
	}
	return (nb);
}
