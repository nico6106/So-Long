/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:09:33 by nlesage           #+#    #+#             */
/*   Updated: 2022/11/12 10:56:02 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*t1;
	const unsigned char	*t2;
	size_t				i;

	i = 0;
	t1 = s1;
	t2 = s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (*t1 != *t2)
		{
			return (*t1 - *t2);
		}
		t1++;
		t2++;
		i++;
	}
	return (0);
}
