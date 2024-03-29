# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 08:32:06 by nlesage           #+#    #+#              #
#    Updated: 2022/12/09 14:45:04 by nlesage          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		= main.c \
				load_map.c \
				verif_map.c \
				ft_free_element.c \
				verif_map_valid_path.c \
				lists.c \
				handle_struct_map.c \
				init_screen.c \
				update_screen.c \
				end_game.c \
				init_variables.c \
				player_move.c

SRCS_BONUS	= main.c \
				load_map.c \
				verif_map.c \
				ft_free_element.c \
				verif_map_valid_path.c \
				lists.c \
				handle_struct_map.c \
				bonus_ennemy_move.c \
				bonus_ennemy.c \
				bonus_end_game.c \
				bonus_init_screen.c \
				bonus_init_variables.c \
				bonus_player_move.c \
				bonus_screen.c \
				bonus_update_screen.c

NAME		= so_long

NAME_B		= so_long_bonus

LIBFT_DIR	= Libft/

LIBFT		= libft.a

HEADERS		= Includes/

FLAGS		= -Wall -Wextra -Werror

FLAGS_XML	= -L./mlx_linux -lmlx -lXext -lX11

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

.c.o:
			gcc ${FLAGS} -I ${HEADERS} -I./mlx_linux/ -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C ${LIBFT_DIR}
			gcc ${FLAGS} -I ${HEADERS} -I./mlx_linux/ -o ${NAME} ${OBJS} -L${LIBFT_DIR} -lft ${FLAGS_XML}

${NAME_B}:	${OBJS_BONUS}
			make -C ${LIBFT_DIR}
			gcc ${FLAGS} -I ${HEADERS} -I./mlx_linux/ -o ${NAME_B} ${OBJS_BONUS} -L${LIBFT_DIR} -lft ${FLAGS_XML}

all:		${NAME}

bonus:		${NAME_B}

clean_lib:	
			make clean -C ${LIBFT_DIR}

fclean_lib:	
			make fclean -C ${LIBFT_DIR}

clean:		clean_lib
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:		clean fclean_lib
			rm -f ${NAME} ${NAME_B}

re:			fclean all

.PHONY:		clean, fclean, re, bonus, add, clean_lib, fclean_lib
