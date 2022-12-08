/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:24:39 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/08 18:08:28 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "graphs.h"

int	ft_end_game(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	ft_end_images(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_clear_map(data->map.map);
	exit (0);
}

void	ft_end_images(t_data *data)
{
	if (data->txt.floor.img)
		mlx_destroy_image(data->mlx, data->txt.floor.img);
	if (data->txt.wall.img)
		mlx_destroy_image(data->mlx, data->txt.wall.img);
	if (data->txt.collect1.img)
		mlx_destroy_image(data->mlx, data->txt.collect1.img);
	if (data->txt.collect2.img)
		mlx_destroy_image(data->mlx, data->txt.collect2.img);
	if (data->txt.collect3.img)
		mlx_destroy_image(data->mlx, data->txt.collect3.img);
	if (data->txt.exit.img)
		mlx_destroy_image(data->mlx, data->txt.exit.img);
	if (data->txt.pla_f.img)
		mlx_destroy_image(data->mlx, data->txt.pla_f.img);
	if (data->txt.pla_b.img)
		mlx_destroy_image(data->mlx, data->txt.pla_b.img);
	if (data->txt.pla_l.img)
		mlx_destroy_image(data->mlx, data->txt.pla_l.img);
	if (data->txt.pla_r.img)
		mlx_destroy_image(data->mlx, data->txt.pla_r.img);
	if (data->txt.rect.img)
		mlx_destroy_image(data->mlx, data->txt.rect.img);
	if (data->txt.ennemy.img)
		mlx_destroy_image(data->mlx, data->txt.ennemy.img);
}
