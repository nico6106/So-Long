# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 08:32:06 by nlesage           #+#    #+#              #
#    Updated: 2022/12/07 12:17:03 by nlesage          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		= main.c load_map.c verif_map.c ft_free_element.c verif_map_valid_path.c lists.c handle_struct_map.c init_map.c update_map.c

NAME		= so_long

LIBFT_DIR	= Libft/

LIBFT		= libft.a

HEADERS		= Includes/

FLAGS		= -Wall -Wextra -Werror

FLAGS_XML	= -L./mlx_linux -lmlx -lXext -lX11

OBJS		= ${SRCS:.c=.o}

.c.o:
			gcc ${FLAGS} -I ${HEADERS} -I./mlx_linux/ -c $< -o ${<:.c=.o}

${NAME}:	add
			gcc ${FLAGS} -I ${HEADERS} -I./mlx_linux/ -o ${NAME} ${OBJS} -L${LIBFT_DIR} -lft ${FLAGS_XML}

all:		${NAME}

add:		${OBJS}
			make -C ${LIBFT_DIR}

clean_lib:	
			make clean -C ${LIBFT_DIR}

fclean_lib:	
			make fclean -C ${LIBFT_DIR}

clean:		clean_lib
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:		clean fclean_lib
			rm -f ${NAME}

re:			fclean all

bonus:		all

.PHONY:		clean, fclean, re, bonus, all, add, clean_lib, fclean_lib
