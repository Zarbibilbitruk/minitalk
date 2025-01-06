/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:55:53 by tautin--          #+#    #+#             */
/*   Updated: 2024/05/27 17:27:23 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ft_s1;
	char	*ft_s2;
	char	*new_s;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = -1;
	j = -1;
	ft_s1 = (char *)s1;
	ft_s2 = (char *)s2;
	new_s = malloc(sizeof(char) * (ft_strlen(ft_s1) + ft_strlen(ft_s2) + 1));
	if (!new_s)
		return (NULL);
	while (ft_s1[++i])
		new_s[i] = ft_s1[i];
	while (ft_s2[++j])
		new_s[i + j] = ft_s2[j];
	new_s[i + j] = '\0';
	return (new_s);
}
