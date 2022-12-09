/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:15:45 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/09 15:23:28 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "graphs.h"

int	ft_play(t_map map)
{
	t_data	data;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
	{
		ft_putstr_fd("Error\nCould not load the environment\n", 2);
		return (MLX_ERROR);
	}
	ft_init_ptrs(&data, map);
	data.win = mlx_new_window(data.mlx, data.win_w, data.win_h, "So Long!");
	if (data.win == NULL)
	{
		free(data.win);
		return (MLX_ERROR);
	}
	data.map.map[data.player.y][data.player.x] = '0';
	ft_init_import_image(&data);
	ft_render_init(&data, -1, -1);
	mlx_hook(data.win, DestroyNotify, 1L << 17, &ft_end_game, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop_hook(data.mlx, &ft_render, &data);
	mlx_loop(data.mlx);
	return (0);
}

void	ft_render_init(t_data *data, int i, int j)
{
	char	**map;

	map = data->map.map;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0')
				ft_show_element(data, &data->txt.floor, i, j);
			if (map[i][j] == '1')
				ft_show_element(data, &data->txt.wall, i, j);
			if (map[i][j] == 'C')
				ft_show_element(data, &data->txt.collect1, i, j);
			if (map[i][j] == 'E')
				ft_show_element(data, &data->txt.exit, i, j);
			if (j == data->player.x && i == data->player.y)
				ft_show_element(data, &data->txt.pla_f, i, j);
		}
	}
}

int	ft_show_element(t_data *data, t_img *img, int i, int j)
{
	if (img->height == 0 || img->width == 0)
	{
		ft_putstr_fd("Error\nThere is an issue with one of the image.\n", 2);
		ft_end_game(data);
	}
	mlx_put_image_to_window(data->mlx, data->win, img->img,
		j * SIZE_IMG, i * SIZE_IMG);
	return (0);
}

int	ft_init_import_image(t_data *data)
{
	if (data->win == NULL)
		return (1);
	ft_import_image(data, &data->txt.floor, "./objets/grass.xpm");
	ft_import_image(data, &data->txt.wall, "./objets/wall.xpm");
	ft_import_image(data, &data->txt.exit, "./objets/panel_end.xpm");
	ft_import_image(data, &data->txt.collect1, "./objets/bird1.xpm");
	ft_import_image(data, &data->txt.pla_b, "./objets/player_back.xpm");
	ft_import_image(data, &data->txt.pla_f, "./objets/player_front.xpm");
	ft_import_image(data, &data->txt.pla_l, "./objets/player_left.xpm");
	ft_import_image(data, &data->txt.pla_r, "./objets/player_right.xpm");
	return (0);
}

int	ft_import_image(t_data *data, t_img *img, char *pathname)
{
	img->img = mlx_xpm_file_to_image(data->mlx, pathname,
			&img->width, &img->height);
	if (!img->img || img->height == 0 || img->width == 0)
	{
		ft_putstr_fd("Error\nThere is an issue with one of the image.\n", 2);
		ft_end_game(data);
	}
	return (0);
}
