/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:15:45 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/07 18:26:33 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_play(t_map map)
{
	t_data	data;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (MLX_ERROR);
	data.map = map;
	data.player = ft_extract_coord(data.map.map, 'P');
	data.map.map[data.player.y][data.player.x] = '0';
	data.collected = 0;
	data.nb_moves = 0;
	data.win_h = SIZE_IMG * data.map.nb_row;
	data.win_w = SIZE_IMG * data.map.nb_column;
	data.win_ptr = mlx_new_window(data.mlx, data.win_w, data.win_h, "So Long!");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	ft_init_import_image(&data);
	ft_render_init(&data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &ft_end_game, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop_hook(data.mlx, &ft_render, &data);
	mlx_loop(data.mlx);
	return (0);
}

int	ft_render_init(t_data *data)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = data->map.map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				ft_show_element(data, &data->txt.floor, i, j);
			if (map[i][j] == '1')
				ft_show_element(data, &data->txt.wall, i, j);
			if (map[i][j] == 'C')
				ft_show_element(data, &data->txt.collect, i, j);
			if (map[i][j] == 'E')
				ft_show_element(data, &data->txt.exit, i, j);
			if (j == data->player.x && i == data->player.y)
				ft_show_element(data, &data->txt.player, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_show_element(t_data *data, t_img *img, int i, int j)
{
	mlx_put_image_to_window(data->mlx, data->win_ptr, img->img, j * SIZE_IMG, i * SIZE_IMG);
	return (0);
}

int	ft_init_import_image(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	ft_import_image(data, &data->txt.floor, "./objets/grass.xpm");
	ft_import_image(data, &data->txt.wall, "./objets/wall.xpm");
	ft_import_image(data, &data->txt.exit, "./objets/panel_end.xpm");
	ft_import_image(data, &data->txt.collect, "./objets/collect.xpm");
	ft_import_image(data, &data->txt.player, "./objets/player.xpm");
	//ft_import_image(data, &data->txt.ennemy, "./objets/ennemy.xpm");
	return (0);
}

int	ft_import_image(t_data *data, t_img *img, char *pathname)
{
	img->img = mlx_xpm_file_to_image(data->mlx, pathname, &img->width, &img->height);
	return (0);
}
