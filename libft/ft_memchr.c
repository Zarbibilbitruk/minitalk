/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:03:32 by tautin--          #+#    #+#             */
/*   Updated: 2024/05/31 16:12:25 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	char			*ft_s;

	i = 0;
	ft_s = (void *)s;
	while (i < n)
	{
		if (ft_s[i] == (char)c)
			return (&ft_s[i]);
		i++;
	}
	return (NULL);
}
