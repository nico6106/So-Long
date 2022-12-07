/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:55:42 by nlesage           #+#    #+#             */
/*   Updated: 2022/11/11 09:52:05 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	len_dest;
	size_t	len_src;

	j = 0;
	if (dst == NULL && size == 0)
		return (0);
	len_dest = ft_strlen((const char *)dst);
	len_src = 0;
	while (src[len_src])
		len_src++;
	if (size == 0 || len_dest > size)
		return (size + len_src);
	while (src[j] != '\0' && (len_dest + j < size - 1))
	{
		dst[len_dest + j] = src[j];
		j++;
	}
	dst[len_dest + j] = '\0';
	return (len_dest + len_src);
}
