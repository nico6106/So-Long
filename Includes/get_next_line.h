/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:51:58 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/02 11:31:32 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_position_gnl
{
	int	start;
	int	end;
	int	is_end;
}	t_position_g;

char			*get_next_line(int fd);
char			*ft_create_row(t_list *lst, int nb_char);
char			*ft_extract_data_from_buffer(t_position_g pi, char *bf, int i);

int				ft_read_row_givelst(int fd, int s, t_list **cha, int nb_c);

void			ft_create_and_lstadd_back(t_list **lst, void *data);
void			ft_lstclear(t_list **lst);

t_position_g	ft_return_position(char *buf, int size);

#endif