/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:45:36 by tautin--          #+#    #+#             */
/*   Updated: 2025/01/06 15:50:37 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbr_len(long nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr >= 1)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int	print_int(long nbr)
{
	int	l;

	l = 0;
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		nbr *= -1;
		l++;
	}
	if (nbr < 10)
		ft_putchar_fd(nbr + '0', 1);
	else
	{
		print_int(nbr / 10);
		print_int(nbr % 10);
	}
	l += nbr_len(nbr);
	return (l);
}
