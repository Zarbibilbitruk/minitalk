/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:06:42 by tautin--          #+#    #+#             */
/*   Updated: 2024/06/03 12:10:07 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_nbr(int n)
{
	int	i;

	if (n == -2147483648)
		return (11);
	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static unsigned int	is_neg(int n, char *str)
{
	unsigned int	nbr;

	if (n < 0)
	{
		str[0] = '-';
		nbr = n * -1;
	}
	else
		nbr = n;
	return (nbr);
}

char	*ft_itoa(int n)
{
	size_t			len;
	char			*str;
	unsigned int	nbr;

	len = len_nbr(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = 48;
		str[1] = '\0';
		return (str);
	}
	nbr = is_neg(n, str);
	str[len] = '\0';
	while (nbr)
	{
		str[len - 1] = (nbr % 10) + 48;
		nbr = nbr / 10;
		len--;
	}
	return (str);
}
