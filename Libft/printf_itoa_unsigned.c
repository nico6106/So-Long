/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:09:41 by nlesage           #+#    #+#             */
/*   Updated: 2022/11/22 16:07:11 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_count_number(unsigned int n);
static char	*ft_feed(char *chaine, int sign, int nb_figure, unsigned int n);

char	*ft_itoa_unsigned(unsigned int n)
{
	char	*chaine;
	int		nb_figure;

	nb_figure = ft_count_number(n);
	chaine = malloc((nb_figure + 0 + 1) * sizeof(char));
	if (!chaine)
		return (NULL);
	chaine = ft_feed(chaine, 0, nb_figure, n);
	return (chaine);
}

static char	*ft_feed(char *chaine, int sign, int nb_figure, unsigned int n)
{
	int	i;

	i = 0;
	while (i < nb_figure + sign)
	{
		chaine[nb_figure + sign - i - 1] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	if (sign != 0)
		chaine[0] = '-';
	chaine[nb_figure + sign] = '\0';
	return (chaine);
}

static int	ft_count_number(unsigned int n)
{
	int	nb;

	nb = 1;
	while (n > 9)
	{
		n = n / 10;
		nb++;
	}
	return (nb);
}
