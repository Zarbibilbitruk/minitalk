/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:38:23 by tautin--          #+#    #+#             */
/*   Updated: 2024/05/28 17:46:50 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	tampon;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		tampon = n * -1;
	}
	else
		tampon = n;
	if (tampon < 10)
		ft_putchar_fd(tampon + '0', fd);
	else
	{
		ft_putnbr_fd(tampon / 10, fd);
		ft_putnbr_fd(tampon % 10, fd);
	}
}

/* structure simplifie
if (i > 9)
	ft_putnbr(i / 10);
write(1, &"0123456789"[i % 10], 1);
*/
