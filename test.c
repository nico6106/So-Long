
//#include "so_long.h"
# include "graphs.h"
#include <stdio.h>


typedef struct	s_rect 
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}	t_rect;


void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

int	ft_end_game(t_data *data)
{
	mlx_clear_window(data->mlx, data->win_ptr);
	mlx_destroy_image(data->mlx, data->txt.wall.img);
	mlx_destroy_image(data->mlx, data->txt.floor.img);
	mlx_destroy_window(data->mlx, data->win_ptr);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		ft_end_game(data);
	return (0);
}

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.height)
	{
		j = rect.x;
		while (j < rect.width)
		{
			my_mlx_pixel_put(img, i, j, rect.color);
			rect.color = rect.color + 1;
			j++;
		}
		i++;
	}
	return (0);
}


int	ft_import_image(t_data *data, t_img *img, char *pathname)
{
	img->img = mlx_xpm_file_to_image(data->mlx, pathname, &img->width, &img->height);
	return (0);
}

int	ft_render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->txt.floor.img, 50, 50);
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->txt.wall.img, 200, 200);
	return (0);
}

int	ft_init_import_image(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	ft_import_image(data, &data->txt.floor, "./objets/grass.xpm");
	ft_import_image(data, &data->txt.wall, "./objets/wall.xpm");
	return (0);
}


int main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "So Long!");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	ft_init_import_image(&data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &ft_end_game, &data); //17, 1L << 0   StructureNotifyMask
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	

	//mlx_put_image_to_window(data->mlx, data->win_ptr, data->txt.floor.img, 50, 50);

	//ft_init_import_image(&data);
	//data.txt.wall.img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	//data.txt.floor.img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);

	//data.txt.wall.addr = mlx_get_data_addr(data.txt.wall.img, &data.txt.wall.bpp, &data.txt.wall.line_len, &data.txt.wall.endian);
	//data.txt.floor.addr = mlx_get_data_addr(data.txt.floor.img, &data.txt.floor.bpp, &data.txt.floor.line_len, &data.txt.floor.endian);

	mlx_loop_hook(data.mlx, &ft_render, &data);
	mlx_loop(data.mlx);
	return (0);
}



void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

int	encode_rgb(int tr, int red, int green, int blue)
{
	return (tr << 24 | red << 16 | green << 8 | blue);
}
