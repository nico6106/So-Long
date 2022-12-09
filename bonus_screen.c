/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:33:23 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/09 12:02:09 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "bonus_graphs.h"

int	ft_show_nb_moves_screen(t_data *data, int nb_moves)
{
	char	*str_moves;
	char	*str_sentence;
	char	*str;

	str_moves = ft_itoa(nb_moves);
	if (!str_moves)
		ft_end_game(data);
	str_sentence = ft_strdup(" moves");
	if (!str_sentence)
		ft_end_game(data);
	str = ft_strjoin(str_moves, str_sentence);
	if (!str)
		ft_end_game(data);
	ft_render_rect(data);
	mlx_put_image_to_window(data->mlx, data->win, data->txt.rect.img,
		0, data->win_h - SIZE_IMG);
	mlx_string_put(data->mlx, data->win, data->win_w / 2 - SIZE_IMG,
		data->win_h - SIZE_IMG / 2, RED, str);
	free(str_moves);
	free(str_sentence);
	free(str);
	return (0);
}

int	ft_render_rect(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE_IMG)
	{
		j = 0;
		while (j < data->win_w)
		{
			my_mlx_pixel_put(&data->txt.rect, j, i, WHITE);
			j++;
		}
		i++;
	}
	return (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *) dst = color;
}

void	ft_make_birds_moves(t_data *data, clock_t time_now)
{
	int	i;
	int	j;

	if (time_now - data->sprite.time_prev > 200000)
	{
		j = -1;
		while (data->map.map[++j])
		{
			i = -1;
			while (data->map.map[j][++i])
			{
				if (data->map.map[j][i] == 'C' && data->sprite.prev == 1)
					ft_show_element(data, &data->txt.collect2, j, i);
				else if (data->map.map[j][i] == 'C' && data->sprite.prev == 2)
					ft_show_element(data, &data->txt.collect3, j, i);
				else if (data->map.map[j][i] == 'C' && data->sprite.prev == 3)
					ft_show_element(data, &data->txt.collect1, j, i);
			}
		}
		data->sprite.prev = (data->sprite.prev + 1) % 4;
		data->sprite.time_prev = time_now;
	}
}
