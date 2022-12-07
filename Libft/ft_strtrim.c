/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:49:40 by nlesage           #+#    #+#             */
/*   Updated: 2022/11/14 09:01:11 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_charset(char const c, char const *set);
static int	ft_first_char(char const *s1, char const *set);
static int	ft_last_char(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len_s1;
	int		char_start;
	int		char_end;
	char	*chaine;

	i = 0;
	if (!s1 | !set)
		return (NULL);
	len_s1 = ft_strlen(s1);
	char_start = ft_first_char(s1, set);
	char_end = ft_last_char(s1, set);
	if (len_s1 == 0 || char_end < 0)
		return (ft_calloc(1, 1));
	chaine = malloc((char_end - char_start + 2) * sizeof(char));
	if (!chaine)
		return (NULL);
	while (char_start <= char_end)
		chaine[i++] = s1[char_start++];
	chaine[i] = '\0';
	return (chaine);
}

static int	ft_first_char(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_is_in_charset(s1[i], set) == 1)
		i++;
	return (i);
}

static int	ft_last_char(char const *s1, char const *set)
{
	int	len_s1;

	len_s1 = ft_strlen(s1);
	if (len_s1 == 0)
		return (-2);
	len_s1 = len_s1 - 1;
	while (len_s1 >= 0 && ft_is_in_charset(s1[len_s1], set) == 1)
		len_s1--;
	return (len_s1);
}

static int	ft_is_in_charset(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
