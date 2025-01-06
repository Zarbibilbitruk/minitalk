/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:17:01 by tautin--          #+#    #+#             */
/*   Updated: 2025/01/06 15:50:15 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_hexa(unsigned int nbr, const char desc)
{
	if (nbr >= 16)
	{
		put_hexa(nbr / 16, desc);
		put_hexa(nbr % 16, desc);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd(nbr + '0', 1);
		else
		{
			if (desc == 'x')
				ft_putchar_fd(nbr - 10 + 'a', 1);
			if (desc == 'X')
				ft_putchar_fd(nbr - 10 + 'A', 1);
		}
	}
}

int	print_hexa(unsigned int nbr, const char desc)
{
	int	length;

	length = 0;
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		put_hexa(nbr, desc);
		while (nbr >= 1)
		{
			length++;
			nbr /= 16;
		}
	}
	return (length);
}
