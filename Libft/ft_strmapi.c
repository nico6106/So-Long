/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:07:33 by nlesage           #+#    #+#             */
/*   Updated: 2022/11/11 17:10:49 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*chaine;

	i = 0;
	if (!(*f) | !s)
		return (NULL);
	len = ft_strlen(s);
	chaine = malloc((len + 1) * sizeof(char));
	if (!chaine)
		return (NULL);
	while (s[i])
	{
		chaine[i] = (*f)(i, s[i]);
		i++;
	}
	chaine[i] = '\0';
	return (chaine);
}
