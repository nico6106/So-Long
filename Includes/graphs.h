/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:11:37 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/09 15:24:04 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHS_H
# define GRAPHS_H

# include <stdlib.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define MLX_ERROR 1
# define SIZE_IMG 32
# define RED 0x00FF0000
# define WHITE 0x00FFFFFF

/*bpp = bits per pixel*/
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_txt
{
	t_img	floor;
	t_img	wall;
	t_img	collect1;
	t_img	exit;
	t_img	pla_b;
	t_img	pla_f;
	t_img	pla_l;
	t_img	pla_r;
}	t_txt;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		win_h;
	int		win_w;
	t_txt	txt;
	t_map	map;
	t_coord	player;
	int		collected;
	int		nb_moves;
}	t_data;

//init_screen.c 
int		ft_play(t_map map);
void	ft_render_init(t_data *data, int i, int j);
int		ft_init_import_image(t_data *data);
int		ft_import_image(t_data *data, t_img *img, char *pathname);
int		ft_show_element(t_data *data, t_img *img, int i, int j);

//update_screen.c
int		ft_render(t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		ft_call_direction_on_keypress(int keysym, t_data *data);
int		ft_h_items(t_data *data, int i, int j, char **map);

//player_move.c
int		ft_direction(t_data *data, int mouv, int i, int j);
int		ft_mouvement_possible(t_data *data, int mouv, int x, int y);

//end_game.c
int		ft_end_game(t_data *data);
void	ft_end_images(t_data *data);

//init_variables.c
int		ft_init_ptrs(t_data *data, t_map map);
int		ft_init_ptrs_img(t_img *img);

#endif