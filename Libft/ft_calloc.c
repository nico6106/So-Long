/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:39:00 by nlesage           #+#    #+#             */
/*   Updated: 2022/11/12 14:32:39 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*table;

	if ((nmemb == SIZE_MAX) | (size == SIZE_MAX))
		return (NULL);
	table = malloc(nmemb * size);
	if (!table)
		return (NULL);
	ft_bzero(table, nmemb * size);
	return (table);
}
