/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:17:34 by tautin--          #+#    #+#             */
/*   Updated: 2025/01/06 15:51:03 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	u_nbr_len(unsigned long nbr)
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

int	print_u(unsigned long nbr)
{
	int	l;

	l = 0;
	if (nbr < 10)
		ft_putchar_fd(nbr + '0', 1);
	else
	{
		print_u(nbr / 10);
		print_u(nbr % 10);
	}
	l += u_nbr_len(nbr);
	return (l);
}
