/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_update_screen.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:16:59 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/09 12:20:49 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "bonus_graphs.h"

int	ft_render(t_data *data)
{
	if (data->win == NULL)
		return (1);
	ft_make_birds_moves(data, clock());
	if (data->ennemy.prev != 0)
		ft_make_ennemy_moves(data, clock() % 4 + 1, data->ennemy.position.x,
			data->ennemy.position.y);
	if (data->ennemy.position.y == data->player.y
		&& data->ennemy.position.x == data->player.x)
	{
		ft_printf("You lost to your ennemy. Try again!\n");
		ft_end_game(data);
	}
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	int		prev_nb_moves;
	int		x;
	int		y;

	y = data->player.y;
	x = data->player.x;
	prev_nb_moves = data->nb_moves;
	ft_call_direction_on_keypress(keysym, data);
	if (ft_h_items(data, x, y, data->map.map) == 1)
		ft_end_game(data);
	if (prev_nb_moves != data->nb_moves)
		ft_show_nb_moves_screen(data, data->nb_moves);
	return (0);
}

int	ft_call_direction_on_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_printf("You quit before the end of the game\n");
		ft_end_game(data);
	}
	if (keysym == 119 || keysym == 65362)
		ft_direction(data, 1, data->player.x, data->player.y);
	if (keysym == 115 || keysym == 65364)
		ft_direction(data, 2, data->player.x, data->player.y);
	if (keysym == 97 || keysym == 65361)
		ft_direction(data, 3, data->player.x, data->player.y);
	if (keysym == 100 || keysym == 65363)
		ft_direction(data, 4, data->player.x, data->player.y);
	if (keysym == 107)
		ft_kill_ennemy(data);
	return (0);
}

int	ft_h_items(t_data *data, int i, int j, char **map)
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
		ft_printf("You won in %d moves! Well done!\n", data->nb_moves);
		data->map.map[y][x] = '0';
		return (1);
	}
	else if (map[y][x] == 'E')
	{
		ft_show_element(data, &data->txt.exit, data->player.y, data->player.x);
		ft_show_element(data, &data->txt.pla_f, j, i);
		data->player.y = j;
		data->player.x = i;
		data->nb_moves = data->nb_moves - 1;
	}
	return (0);
}
