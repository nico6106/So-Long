/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_element.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:45:02 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/03 17:23:13 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_clear_map_after_error(char **map, int nb_to_free)
{
	int	i;

	i = 0;
	while (map[i] && i < nb_to_free)
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}

void	ft_clear_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
