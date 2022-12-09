/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init_variables.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:30:50 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/09 15:27:33 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "bonus_graphs.h"

int	ft_init_ptrs(t_data *data, t_map map)
{
	data->map = map;
	data->player = ft_extract_coord(data->map.map, 'P');
	data->win_h = SIZE_IMG * (data->map.nb_row + 1);
	data->win_w = SIZE_IMG * data->map.nb_column;
	ft_init_ptrs_img(&data->txt.floor);
	ft_init_ptrs_img(&data->txt.wall);
	ft_init_ptrs_img(&data->txt.exit);
	ft_init_ptrs_img(&data->txt.collect1);
	ft_init_ptrs_img(&data->txt.collect2);
	ft_init_ptrs_img(&data->txt.collect3);
	ft_init_ptrs_img(&data->txt.pla_b);
	ft_init_ptrs_img(&data->txt.pla_f);
	ft_init_ptrs_img(&data->txt.pla_l);
	ft_init_ptrs_img(&data->txt.pla_r);
	ft_init_ptrs_img(&data->txt.rect);
	ft_init_ptrs_img(&data->txt.ennemy);
	data->sprite.time_prev = clock();
	data->sprite.prev = 1;
	data->ennemy.time_prev = clock();
	data->ennemy.prev = 0;
	data->ennemy.position.x = 0;
	data->ennemy.position.y = 0;
	data->collected = 0;
	data->nb_moves = 0;
	return (0);
}

int	ft_init_ptrs_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
	img->height = 0;
	img->width = 0;
	return (0);
}
