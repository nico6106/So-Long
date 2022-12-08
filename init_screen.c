/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:15:45 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/08 18:19:59 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "graphs.h"

int	ft_play(t_map map)
{
	t_data	data;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (MLX_ERROR);
	ft_init_ptrs(&data);
	data.map = map;
	data.player = ft_extract_coord(data.map.map, 'P');
	data.map.map[data.player.y][data.player.x] = '0';
	data.win_h = SIZE_IMG * (data.map.nb_row + 1);
	data.win_w = SIZE_IMG * data.map.nb_column;
	data.win = mlx_new_window(data.mlx, data.win_w, data.win_h, "So Long!");
	if (data.win == NULL)
	{
		free(data.win);
		return (MLX_ERROR);
	}
	ft_create_ennemy(&data);
	ft_init_import_image(&data);
	ft_render_init(&data, -1, -1);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &ft_end_game, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop_hook(data.mlx, &ft_render, &data);
	mlx_loop(data.mlx);
	return (0);
}

void	ft_render_init(t_data *data, int i, int j)
{
	char	**map;

	map = data->map.map;
	ft_show_nb_moves_screen(data, data->nb_moves);
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
			if (map[i][j] == 'M')
				ft_show_element(data, &data->txt.ennemy, i, j);
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
	ft_import_image(data, &data->txt.collect2, "./objets/bird2.xpm");
	ft_import_image(data, &data->txt.collect3, "./objets/bird3.xpm");
	ft_import_image(data, &data->txt.pla_b, "./objets/player_back.xpm");
	ft_import_image(data, &data->txt.pla_f, "./objets/player_front.xpm");
	ft_import_image(data, &data->txt.pla_l, "./objets/player_left.xpm");
	ft_import_image(data, &data->txt.pla_r, "./objets/player_right.xpm");
	ft_import_image(data, &data->txt.ennemy, "./objets/ennemy.xpm");
	data->txt.rect.img = mlx_new_image(data->mlx, data->win_w, SIZE_IMG);
	data->txt.rect.addr = mlx_get_data_addr(data->txt.rect.img,
			&data->txt.rect.bpp, &data->txt.rect.line_len,
			&data->txt.rect.endian);
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
