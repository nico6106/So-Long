/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:40:55 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/08 18:08:34 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "graphs.h"

void	ft_make_ennemy_moves(t_data *data, int dir, int x, int y)
{
	if (clock() - data->ennemy.time_prev > 150000)
	{
		if (dir == 1 && data->map.map[y - 1][x] == '0')
		{
			ft_insert_move_in_tab(data, dir, x, y);
			ft_call_showtab_ennemy(data, dir, x, y);
		}
		else if (dir == 2 && data->map.map[y][x - 1] == '0')
		{
			ft_insert_move_in_tab(data, dir, x, y);
			ft_call_showtab_ennemy(data, dir, x, y);
		}
		else if (dir == 3 && data->map.map[y + 1][x] == '0')
		{
			ft_insert_move_in_tab(data, dir, x, y);
			ft_call_showtab_ennemy(data, dir, x, y);
		}
		else if (dir == 4 && data->map.map[y][x + 1] == '0')
		{
			ft_insert_move_in_tab(data, dir, x, y);
			ft_call_showtab_ennemy(data, dir, x, y);
		}
		data->ennemy.time_prev = clock();
	}
}

void	ft_insert_move_in_tab(t_data *data, int dir, int x, int y)
{
	if (dir == 1)
	{
		data->map.map[y][x] = '0';
		data->map.map[y - 1][x] = 'M';
		data->ennemy.position.y = data->ennemy.position.y - 1;
	}
	else if (dir == 2)
	{
		data->map.map[y][x] = '0';
		data->map.map[y][x - 1] = 'M';
		data->ennemy.position.x = data->ennemy.position.x - 1;
	}
	else if (dir == 3)
	{
		data->map.map[y][x] = '0';
		data->map.map[y + 1][x] = 'M';
		data->ennemy.position.y = data->ennemy.position.y + 1;
	}
	else if (dir == 4)
	{
		data->map.map[y][x] = '0';
		data->map.map[y][x + 1] = 'M';
		data->ennemy.position.x = data->ennemy.position.x + 1;
	}
}

void	ft_call_showtab_ennemy(t_data *data, int dir, int x, int y)
{
	if (dir == 1)
	{
		ft_show_element(data, &data->txt.floor, y, x);
		ft_show_element(data, &data->txt.ennemy, y - 1, x);
	}
	else if (dir == 2)
	{
		ft_show_element(data, &data->txt.floor, y, x);
		ft_show_element(data, &data->txt.ennemy, y, x - 1);
	}
	else if (dir == 3)
	{
		ft_show_element(data, &data->txt.floor, y, x);
		ft_show_element(data, &data->txt.ennemy, y + 1, x);
	}
	else if (dir == 4)
	{
		ft_show_element(data, &data->txt.floor, y, x);
		ft_show_element(data, &data->txt.ennemy, y, x + 1);
	}
}
