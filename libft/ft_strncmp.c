/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:01:16 by tautin--          #+#    #+#             */
/*   Updated: 2024/05/23 17:00:45 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*ft_s1;
	unsigned char	*ft_s2;

	i = 0;
	ft_s1 = (unsigned char *)s1;
	ft_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((ft_s1[i] || ft_s2[i]) && i < n)
	{
		if (ft_s1[i] != ft_s2[i])
			return (ft_s1[i] - ft_s2[i]);
		i++;
	}
	if (i != n)
		return (*ft_s1 - *ft_s2);
	return (*ft_s1 - *ft_s2);
}
