/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:05:56 by nlesage           #+#    #+#             */
/*   Updated: 2022/11/12 15:45:00 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_nb_word(char const *s, char c, int nb_word);
static int	ft_count_nb_char(char const *s, char c, int i);
static char	**ft_complete_tab(char **tab, char const *s, char c, int i);
static void	ft_free_double(char **tab, int nb_word);

char	**ft_split(char const *s, char c)
{
	int		i;
	int		nb_word;
	char	**tab;

	i = 0;
	if (!s)
		return (NULL);
	nb_word = ft_count_nb_word(s, c, 0);
	tab = malloc((nb_word + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (s[i] && s[i] == c)
		i++;
	tab = ft_complete_tab(tab, s, c, i);
	if (tab == NULL)
	{
		ft_free_double(tab, nb_word + 1);
		return (NULL);
	}
	tab[nb_word] = 0;
	return (tab);
}

static void	ft_free_double(char **tab, int nb_word)
{
	while (nb_word != 0)
	{
		free(tab[nb_word]);
		nb_word--;
	}
	free(tab);
}

static char	**ft_complete_tab(char **tab, char const *s, char c, int i)
{
	int	nb_char;
	int	nb_word;
	int	j;

	nb_word = -1;
	while (s[i])
	{
		if (s[i] != c)
		{
			nb_char = ft_count_nb_char(s, c, i);
			tab[++nb_word] = malloc((nb_char + 1) * sizeof(char));
			if (!tab[nb_word])
				return (NULL);
			j = 0;
			while (s[i] && s[i] != c)
			{
				tab[nb_word][j++] = s[i];
				i++;
			}
			tab[nb_word][j] = '\0';
			i--;
		}
		i++;
	}
	return (tab);
}

static int	ft_count_nb_char(char const *s, char c, int i)
{
	int	nb_char;

	nb_char = 0;
	while (s[i] && s[i] != c)
	{
		nb_char++;
		i++;
	}
	return (nb_char);
}

static int	ft_count_nb_word(char const *s, char c, int nb_word)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && word == 0)
			word = 1;
		if (s[i] == c)
		{
			while (s[i] && s[i] == c)
				i++;
			i--;
			nb_word++;
		}
		i++;
	}
	if ((nb_word == 0 && word == 1) || (s[i - 1] != c && s[0] != '\0'))
		nb_word++;
	return (nb_word);
}
