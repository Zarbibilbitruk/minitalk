/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:23:08 by tautin--          #+#    #+#             */
/*   Updated: 2025/01/06 15:50:55 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_pointer(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		put_pointer(ptr / 16);
		put_pointer(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd(ptr + '0', 1);
		else
			ft_putchar_fd(ptr - 10 + 'a', 1);
	}
}

int	print_p(unsigned long long ptr)
{
	int	length;

	length = 0;
	if (ptr == 0)
		length += write(1, "(nil)", 5);
	else
	{
		length += write(1, "0x", 2);
		put_pointer(ptr);
		while (ptr >= 1)
		{
			length++;
			ptr /= 16;
		}
	}
	return (length);
}
