/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:54:42 by tautin--          #+#    #+#             */
/*   Updated: 2024/05/31 16:14:15 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ft_s;

	i = 0;
	ft_s = (char *)s;
	while (ft_s[i] && ft_s[i] != (char)c)
		i++;
	if (ft_s[i] != (char)c)
		return (NULL);
	return (&ft_s[i]);
}
