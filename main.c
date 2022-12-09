/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 08:22:03 by nlesage           #+#    #+#             */
/*   Updated: 2022/12/09 11:33:14 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "graphs.h"

void	ft_show_map(char **map);

int	main(int argc, char **argv)
{
	t_map	struct_map;
	char	**map;

	map = ft_return_map(argc, argv);
	if (!map)
		return (1);
	struct_map = ft_create_struct_map(map);
	ft_play(struct_map);
	ft_clear_map(struct_map.map);
	return (0);
}
