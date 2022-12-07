/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:16:59 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/07 18:30:09 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	int	prev_nb_moves;

	prev_nb_moves = data->nb_moves;
	if (keysym == XK_Escape)
		ft_end_game(data);
	if (keysym == 119 || keysym == 65362)
		ft_direction(data, 1, data->player.x, data->player.y);
	if (keysym == 115 || keysym == 65364)
		ft_direction(data, 2, data->player.x, data->player.y);
	if (keysym == 97 || keysym == 65361)
		ft_direction(data, 3, data->player.x, data->player.y);
	if (keysym == 100 || keysym == 65363)
		ft_direction(data, 4, data->player.x, data->player.y);
	if (prev_nb_moves != data->nb_moves)
		ft_printf("%d moves\n", data->nb_moves);
	return (0);
}

int	ft_handle_items(t_data *data, int i, int j, char **map)
{
	int		x;
	int		y;

	y = data->player.y;
	x = data->player.x;
	if (map[y][x] == 'C')
	{
		data->map.map[y][x] = '0';
		data->collected = data->collected + 1;
	}
	if (map[y][x] == 'E' && data->collected == data->map.nb_items)
	{
		data->map.map[y][x] = '0';
		return (1);
	}
	else if (map[y][x] == 'E')
	{
		ft_show_element(data, &data->txt.exit, data->player.y, data->player.x);
		ft_show_element(data, &data->txt.player, j, i);
		data->player.y = j;
		data->player.x = i;
		data->nb_moves = data->nb_moves - 1;
	}
	return (0);
}

int	ft_direction(t_data *data, int mouv, int i, int j)
{
	if (mouv == 1 && ft_mouvement_possible(data, mouv, 0, 0) == 1)
	{
		data->nb_moves = data->nb_moves + 1;
		ft_show_element(data, &data->txt.floor, j, i);
		ft_show_element(data, &data->txt.player, data->player.y, data->player.x);
	}
	else if (mouv == 2 && ft_mouvement_possible(data, mouv, 0, 0) == 1)
	{
		data->nb_moves = data->nb_moves + 1;
		ft_show_element(data, &data->txt.floor, j, i);
		ft_show_element(data, &data->txt.player, data->player.y, data->player.x);
	}
	else if (mouv == 3 && ft_mouvement_possible(data, mouv, 0, 0) == 1)
	{
		data->nb_moves = data->nb_moves + 1;
		ft_show_element(data, &data->txt.floor, j, i);
		ft_show_element(data, &data->txt.player, data->player.y, data->player.x);
	}
	else if (mouv == 4 && ft_mouvement_possible(data, mouv, 0, 0) == 1)
	{
		data->nb_moves = data->nb_moves + 1;
		ft_show_element(data, &data->txt.floor, j, i);
		ft_show_element(data, &data->txt.player, data->player.y, data->player.x);
	}
	if (ft_handle_items(data, i, j, data->map.map) == 1)
		ft_end_game(data);
	return (0);
}

int	ft_mouvement_possible(t_data *data, int mouv, int x, int y)
{
	y = data->player.y;
	x = data->player.x;
	if (ft_is_in_charset(data->map.map[y - 1][x], "0EC") && mouv == 1)
	{
		data->player.y = y - 1;
		return (1);
	}
	else if (ft_is_in_charset(data->map.map[y + 1][x], "0EC") && mouv == 2)
	{
		data->player.y = y + 1;
		return (1);
	}
	else if (ft_is_in_charset(data->map.map[y][x - 1], "0EC") && mouv == 3)
	{
		data->player.x = x - 1;
		return (1);
	}
	else if (ft_is_in_charset(data->map.map[y][x + 1], "0EC") && mouv == 4)
	{
		data->player.x = x + 1;
		return (1);
	}
	return (0);
}

int	ft_end_game(t_data *data)
{
	mlx_clear_window(data->mlx, data->win_ptr);
	mlx_destroy_image(data->mlx, data->txt.floor.img);
	mlx_destroy_image(data->mlx, data->txt.wall.img);
	mlx_destroy_image(data->mlx, data->txt.collect.img);
	mlx_destroy_image(data->mlx, data->txt.exit.img);
	mlx_destroy_image(data->mlx, data->txt.player.img);
	//mlx_destroy_image(data->mlx, data->txt.ennemy.img);
	mlx_destroy_window(data->mlx, data->win_ptr);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_clear_map(data->map.map);
	exit (0);
}
