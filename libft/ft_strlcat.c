/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:33:42 by tautin--          #+#    #+#             */
/*   Updated: 2024/05/24 17:31:44 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	len_dest;
	size_t	i;

	i = 0;
	if (dst == 0 && siz == 0)
		return (ft_strlen(src) + siz);
	len_dest = ft_strlen(dst);
	if (siz <= len_dest)
		return (ft_strlen(src) + siz);
	while (src[i] && (len_dest + i < siz - 1))
	{
		dst[len_dest + i] = src[i];
		i++;
	}
	dst[len_dest + i] = '\0';
	return (ft_strlen(src) + len_dest);
}
