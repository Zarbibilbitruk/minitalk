/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:40:22 by tautin--          #+#    #+#             */
/*   Updated: 2024/05/24 16:26:05 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*ft_dest;
	char			*ft_src;

	i = 0;
	ft_dest = (char *)dest;
	ft_src = (char *)src;
	if ((ft_dest == 0 && ft_src == 0) || ft_dest == ft_src)
		return (dest);
	while (i < n)
	{
		ft_dest[i] = ft_src[i];
		i++;
	}
	return (dest);
}
