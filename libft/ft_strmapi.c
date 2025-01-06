/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:31:59 by tautin--          #+#    #+#             */
/*   Updated: 2024/05/28 16:37:21 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len_s;
	char	*ft_s;

	if (s == NULL)
		return (NULL);
	i = 0;
	len_s = ft_strlen(s);
	ft_s = malloc(sizeof(char) * (len_s + 1));
	if (!ft_s)
		return (NULL);
	while (i < len_s)
	{
		ft_s[i] = f(i, s[i]);
		i++;
	}
	ft_s[len_s] = '\0';
	return (ft_s);
}
