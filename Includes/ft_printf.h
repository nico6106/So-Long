/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:17:02 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/02 09:01:05 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_list_printf
{
	void					*content;
	int						type;
	int						flag;
	int						flag2;
	int						width;
	struct s_list_printf	*next;
}	t_list_p;

typedef struct s_position
{
	int			start;
	int			end;
	const char	*chaine;
}	t_position;

int			ft_printf(const char *s, ...);
int			ft_count_nb_arg(const char *s);

t_list_p	*ft_extract_data_from_s(const char *s);
int			ft_add_txt_to_lst(t_list_p **lst, const char *s, int start);
void		ft_add_elem_back_lst(t_list_p **lst, void *data, int ty, int flag);

char		*ft_extract_text(const char *s, int start, int end);
int			ft_check_and_treat_flag(t_list_p **lst, t_position p);

int			ft_add_flag_to_lst(t_list_p **lst, t_position p, int check, int i);
int			ft_is_in_charset(char c, char *set);

char		*ft_return_nb_base(char *base, unsigned long int nb, int position);
char		*ft_reverse_string(char *s);

int			ft_add_type(t_position p);

int			ft_handle_nb_base10(t_list_p **lst, long nb);
int			ft_handle_char(t_list_p **lst, char c);
int			ft_handle_string(t_list_p **lst, char *arg);
int			ft_handl_add(t_list_p **lst, unsigned long long address);
int			ft_comp_lst_wih_arg(t_list_p **lst, va_list p, int a, t_list_p *b);

int			ft_handle_nb16(t_list_p **lst, int op_base, unsigned long int nb);
int			ft_handle_nb_u_base10(t_list_p **lst, long nb);

char		*ft_itoa_unsigned(unsigned int n);
char		*ft_add_ox(char *data);
char		*ft_add_text_to_data(char *data, char *adding);

int			ft_show_elem(t_list_p *lst, int i);

char		*ft_return_data_from_text(char *text);
char		*ft_return_nb_base_int(char *base, unsigned int nb, int position);
int			ft_abs(int nb);

//bonus
int			ft_add_flag(t_position p);
int			ft_add_other_flag(t_list_p **lst, t_position p);
int			ft_data_align_left(t_list_p **lst, char *data, char c);
int			ft_data_align_right(t_list_p **lst, char *data, char c, int len);
int			ft_final_treatment(t_list_p **lst);
char		*ft_to_next_number(char *data, char c);
int			ft_handle_sign_in_data(t_list_p **lst, char **data, char c, int l);
char		*ft_return_tab_amended(t_list_p **lst, char *data, int to_add_last);

//libft.a
int			ft_lstclear_printf(t_list_p **lst);

#endif
