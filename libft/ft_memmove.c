/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:40:00 by tautin--          #+#    #+#             */
/*   Updated: 2024/05/24 16:35:01 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ft_dest;
	char	*ft_src;

	ft_dest = (char *)dest;
	ft_src = (char *)src;
	if ((ft_dest == 0 && ft_src == 0) || ft_dest == ft_src)
		return (dest);
	if (ft_src < ft_dest)
	{
		while (n > 0)
		{
			ft_dest[n - 1] = ft_src[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(ft_dest, ft_src, n);
	return (dest);
}
