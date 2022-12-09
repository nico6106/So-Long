/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_player_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:49:53 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/09 12:02:07 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "bonus_graphs.h"

int	ft_direction(t_data *data, int mouv, int i, int j)
{
	if (mouv == 1 && ft_mouvement_possible(data, mouv, 0, 0) == 1)
	{
		data->nb_moves = data->nb_moves + 1;
		ft_show_element(data, &data->txt.floor, j, i);
		ft_show_element(data, &data->txt.pla_b, data->player.y, data->player.x);
	}
	else if (mouv == 2 && ft_mouvement_possible(data, mouv, 0, 0) == 1)
	{
		data->nb_moves = data->nb_moves + 1;
		ft_show_element(data, &data->txt.floor, j, i);
		ft_show_element(data, &data->txt.pla_f, data->player.y, data->player.x);
	}
	else if (mouv == 3 && ft_mouvement_possible(data, mouv, 0, 0) == 1)
	{
		data->nb_moves = data->nb_moves + 1;
		ft_show_element(data, &data->txt.floor, j, i);
		ft_show_element(data, &data->txt.pla_l, data->player.y, data->player.x);
	}
	else if (mouv == 4 && ft_mouvement_possible(data, mouv, 0, 0) == 1)
	{
		data->nb_moves = data->nb_moves + 1;
		ft_show_element(data, &data->txt.floor, j, i);
		ft_show_element(data, &data->txt.pla_r, data->player.y, data->player.x);
	}
	return (0);
}

int	ft_mouvement_possible(t_data *data, int mouv, int x, int y)
{
	y = data->player.y;
	x = data->player.x;
	if (ft_is_in_charset(data->map.map[y - 1][x], "0EMC") && mouv == 1)
	{
		data->player.y = y - 1;
		return (1);
	}
	else if (ft_is_in_charset(data->map.map[y + 1][x], "0EMC") && mouv == 2)
	{
		data->player.y = y + 1;
		return (1);
	}
	else if (ft_is_in_charset(data->map.map[y][x - 1], "0EMC") && mouv == 3)
	{
		data->player.x = x - 1;
		return (1);
	}
	else if (ft_is_in_charset(data->map.map[y][x + 1], "0EMC") && mouv == 4)
	{
		data->player.x = x + 1;
		return (1);
	}
	return (0);
}
