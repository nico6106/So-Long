/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:24:24 by nlesage           #+#    #+#             */
/*   Updated: 2022/11/11 12:08:24 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_number(int n);
static char	*ft_feed_itoa(char *chaine, int sign, int nb_figure, int n);

char	*ft_itoa(int n)
{
	int		sign;
	char	*chaine;
	int		nb_figure;

	sign = 0;
	if (n == -2147483648)
	{
		chaine = malloc((11 + 1) * sizeof(char));
		if (!chaine)
			return (NULL);
		ft_memcpy(chaine, "-2147483648", 11);
		chaine[11] = '\0';
		return (chaine);
	}
	if (n < 0)
	{
		n = n * -1;
		sign++;
	}
	nb_figure = ft_count_number(n);
	chaine = malloc((nb_figure + sign + 1) * sizeof(char));
	if (!chaine)
		return (NULL);
	chaine = ft_feed_itoa(chaine, sign, nb_figure, n);
	return (chaine);
}

static char	*ft_feed_itoa(char *chaine, int sign, int nb_figure, int n)
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

static int	ft_count_number(int n)
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
