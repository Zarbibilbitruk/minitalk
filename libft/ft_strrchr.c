/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:12:22 by tautin--          #+#    #+#             */
/*   Updated: 2024/05/31 16:13:59 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ft_s;

	ft_s = (char *)s;
	i = ft_strlen(ft_s);
	while (ft_s[i] != (char)c && i >= 0)
		i--;
	if (ft_s[i] != (char)c)
		return (NULL);
	return (&ft_s[i]);
}
