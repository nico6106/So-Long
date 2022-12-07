# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 09:02:27 by nlesage           #+#    #+#              #
#    Updated: 2022/12/01 14:09:04 by nlesage          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_isprint.c ft_putendl_fd.c ft_strlcat.c ft_substr.c ft_atoi.c ft_itoa.c ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c ft_bzero.c ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_toupper.c ft_calloc.c ft_memcmp.c ft_split.c ft_strmapi.c ft_isalnum.c ft_memcpy.c ft_strchr.c ft_strncmp.c ft_isalpha.c ft_memmove.c ft_strdup.c ft_strnstr.c ft_isascii.c ft_memset.c ft_striteri.c ft_strrchr.c ft_isdigit.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c ft_abs.c
SRCS_GNL	= get_next_line_utils.c get_next_line.c
SRCS_PRINTF	= printf_extract_text.c printf_ft_bonus_2.c printf_ft_bonus.c printf_ft_printf.c printf_handle.c printf_initial_analysis.c printf_itoa_unsigned.c printf_lists.c
SRCS_BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

NAME		= libft.a

HEADERS		= Includes/

FLAGS		= -Wall -Wextra -Werror

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

OBJS_GNL	= ${SRCS_GNL:.c=.o}

OBJS_PRINTF	= ${SRCS_PRINTF:.c=.o}

.c.o:
			gcc ${FLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${OBJS_BONUS} ${OBJS_GNL} ${OBJS_PRINTF}
			ar rc ${NAME} ${OBJS} ${OBJS_BONUS} ${OBJS_GNL} ${OBJS_PRINTF}

all:		${NAME}

clean:
			rm -f ${OBJS} ${OBJS_BONUS} ${OBJS_GNL} ${OBJS_PRINTF}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

bonus:		${OBJS} ${OBJS_BONUS}
			ar rc ${NAME} ${OBJS} ${OBJS_BONUS}

.PHONY:		all clean fclean re bonus
