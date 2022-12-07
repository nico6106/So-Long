/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:11:25 by nlesage           #+#    #+#             */
/*   Updated: 2022/11/12 14:35:00 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	c_bis;

	i = 0;
	c_bis = (char)c;
	while (s[i])
		i++;
	while (i >= 0 || !c_bis)
	{
		if (s[i] == c_bis)
			return ((char *) &s[i]);
		i--;
	}
	return (0);
}
