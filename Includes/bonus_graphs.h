/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_graphs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:11:37 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/09 15:26:18 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_GRAPHS_H
# define BONUS_GRAPHS_H

# include <stdlib.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <time.h>

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
	t_img	collect2;
	t_img	collect3;
	t_img	exit;
	t_img	pla_b;
	t_img	pla_f;
	t_img	pla_l;
	t_img	pla_r;
	t_img	ennemy;
	t_img	rect;
}	t_txt;

typedef struct s_sprite
{
	clock_t	time_prev;
	int		prev;
	t_coord	position;
}	t_sprit;

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
	t_sprit	sprite;
	t_sprit	ennemy;
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

//bonus_screen.c
int		ft_show_nb_moves_screen(t_data *data, int nb_moves);
int		ft_render_rect(t_data *data);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	ft_make_birds_moves(t_data *data, clock_t time_now);

//end_game.c
int		ft_end_game(t_data *data);
void	ft_end_images(t_data *data);

//init_variables.c
int		ft_init_ptrs(t_data *data, t_map map);
int		ft_init_ptrs_img(t_img *img);

//ennemy.c
int		ft_create_ennemy(t_data *data);
void	ft_kill_ennemy(t_data *data);
t_coord	ft_extract_init_pos_ennemy(t_data *data, clock_t position_alea);
t_coord	ft_return_coord_ennemy(t_data *data, t_coord init, int test);

//ennemy_move.c
void	ft_make_ennemy_moves(t_data *data, int dir, int x, int y);
void	ft_insert_move_in_tab(t_data *data, int dir, int x, int y);
void	ft_call_showtab_ennemy(t_data *data, int dir, int x, int y);

#endif