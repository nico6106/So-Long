/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:29:58 by nlesage           #+#    #+#             */
/*   Updated: 2022/11/12 11:50:37 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;
	char	*chaine;

	if (!s1 | !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	chaine = malloc((len_s1 + len_s2 + 1) * sizeof(char const));
	if (!chaine)
		return (NULL);
	i = -1;
	while (s1[++i])
		chaine[i] = s1[i];
	while (s2[i - len_s1])
	{
		chaine[i] = s2[i - len_s1];
		i++;
	}
	chaine[i] = '\0';
	return (chaine);
}
