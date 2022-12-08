/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:37:39 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/08 18:08:37 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "graphs.h"

int	ft_create_ennemy(t_data *data)
{
	t_coord	init;
	t_coord	ennemy;

	init = ft_extract_init_pos_ennemy(data, clock() % 10 + 1);
	ennemy = ft_return_coord_ennemy(data, init, 0);
	if (data->ennemy.prev == 1)
	{
		data->map.map[ennemy.y][ennemy.x] = 'M';
		data->ennemy.time_prev = clock();
		data->ennemy.position.x = ennemy.x;
		data->ennemy.position.y = ennemy.y;
		ft_printf("You have one ennemy on this game\n");
	}
	else
		ft_printf("You don't have an ennemy on this game\n");
	return (0);
}

t_coord	ft_extract_init_pos_ennemy(t_data *data, clock_t position_alea)
{
	t_coord	init;
	int		i;
	int		j;

	i = data->map.nb_column / position_alea;
	j = data->map.nb_row / position_alea;
	if (i <= 1 || i == data->map.nb_column)
		i = data->map.nb_column / 2;
	if (j <= 1 || j == data->map.nb_row)
		j = data->map.nb_row / 2;
	init.x = i;
	init.y = j;
	return (init);
}

t_coord	ft_return_coord_ennemy(t_data *data, t_coord init, int test)
{
	t_coord	ennemy;

	ennemy.x = init.x;
	ennemy.y = init.y;
	while (data->map.map[ennemy.y][ennemy.x] != '0')
	{
		ennemy.y--;
		if (ennemy.y > init.y + data->map.nb_row % 10)
			ennemy.y = ennemy.y + 2;
		ennemy.x--;
		if (ennemy.x > init.x + data->map.nb_column % 10)
			ennemy.x = ennemy.x + 2;
		if (ennemy.x == 0 || ennemy.x == data->map.nb_column - 1)
			ennemy.x = data->map.nb_column / 2;
		if (ennemy.y == 0 || ennemy.y == data->map.nb_row - 1)
			ennemy.y = data->map.nb_row / 2;
		if (test >= 50)
		{
			data->ennemy.prev = 0;
			return (ennemy);
		}
		test++;
	}
	data->ennemy.prev = 1;
	return (ennemy);
}

void	ft_kill_ennemy(t_data *data)
{
	int	x;
	int	y;

	x = data->ennemy.position.x;
	y = data->ennemy.position.y;
	if (data->ennemy.prev != 0)
	{
		data->map.map[y][x] = '0';
		ft_show_element(data, &data->txt.floor, y, x);
		data->ennemy.prev = 0;
		data->ennemy.position.x = 0;
		data->ennemy.position.y = 0;
		ft_printf("You needed help. Your ennemy doesn't exist anymore\n");
	}
}
