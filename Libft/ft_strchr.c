/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:54:04 by nlesage           #+#    #+#             */
/*   Updated: 2022/11/12 14:35:17 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c_bis;

	i = 0;
	c_bis = (char)c;
	while (s[i] || !c_bis)
	{
		if (s[i] == c_bis)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == c_bis)
		return ((char *) &s[i]);
	return (NULL);
}
