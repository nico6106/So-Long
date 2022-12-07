/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 08:47:18 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/07 18:32:30 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"

# include <stdlib.h>
# include <mlx.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_coord
{
	int		x;
	int		y;
	char	c;
}	t_coord;

typedef struct s_list_coord
{
	t_coord				coord;
	struct s_list_coord	*next;
}	t_list_coord;

typedef struct s_map
{
	int				nb_row;
	int				nb_column;
	int				nb_items;
	char			**map;
}	t_map;

# include "graphs.h"

//load_map.c
char	**ft_return_map(int argc, char **argv);
int		ft_check_argv(int argc, char **argv);
t_list	*ft_extract_map(char *map_name);
int		ft_verif_nb_char_per_row(t_list *lst);
char	**ft_assemble_map(t_list *lst);

//verif_map.c   
int		ft_check_map(char **map);
int		ft_check_items(char **map, int i_start, int i_end, int i_tocollect);
int		ft_check_wall(char *row, int option);
int		ft_check_is_rectangle(char **map);
int		ft_check_walls(char **map);

//verif_map_valid_path.c
int		ft_verif_map_is_valid(char **map);
t_map	ft_algo(t_map tp, t_coord start);
t_coord	ft_return_next_coord(char **map, t_coord start, int dir);
t_coord	ft_extract_coord(char **map, char c);

//handle_struct_map.c
t_map	ft_create_struct_map(char **map);
int		ft_count_nb_row_in_tab(char **map);
int		ft_count_items(char **map);
char	**ft_copy_map(char **map, int i, int j);
char	**ft_treat_copy(char **map);

//ft_free_element.c
void	*ft_clear_map_after_error(char **map, int nb_to_free);
void	ft_clear_map(char **map);

//lists.c
int		ft_lst_create_elem_and_addback(t_list **lst, void *data);
int		ft_lst_coord_create_and_addback(t_list_coord **lst, t_coord c);

//main.c
void	ft_show_map(char **map);
#endif