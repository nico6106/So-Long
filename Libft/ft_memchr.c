/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:33:36 by nlesage           #+#    #+#             */
/*   Updated: 2022/11/08 12:08:33 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*t;

	i = 0;
	t = s;
	while (i < n)
	{
		if (*t == (const unsigned char) c)
			return ((void *) t);
		t++;
		i++;
	}
	return (NULL);
}
