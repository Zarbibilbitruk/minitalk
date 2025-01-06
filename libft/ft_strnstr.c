/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:10:27 by tautin--          #+#    #+#             */
/*   Updated: 2024/05/24 18:55:29 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	char		*ft_big;
	char		*ft_little;

	i = 0;
	ft_big = (char *)big;
	ft_little = (char *)little;
	if (ft_big == 0 && len == 0)
		return (NULL);
	if (ft_little[i] == 0)
		return (&ft_big[i]);
	while (ft_big[i] != 0 && i < len)
	{
		j = 0;
		while ((ft_big[i + j] == ft_little[j]) && i + j < len)
		{
			j++;
			if (ft_little[j] == 0)
				return (&ft_big[i]);
		}
		i++;
	}
	return (NULL);
}
