/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:27:44 by nlesage           #+#    #+#             */
/*   Updated: 2022/11/14 09:01:27 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	size_t	len_chaine;
	char	*chaine;

	i = -1;
	len_chaine = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s || len <= 0)
		return (ft_calloc(1, 1));
	while (s[len_chaine + start] && len_chaine < len)
		len_chaine++;
	chaine = malloc((len_chaine + 1) * sizeof(char const));
	if (!chaine)
		return (NULL);
	while (s[++i + start] != '\0' && i < len)
		chaine[i] = s[i + start];
	chaine[len_chaine] = '\0';
	return (chaine);
}
