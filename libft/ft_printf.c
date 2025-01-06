/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:57:08 by tautin--          #+#    #+#             */
/*   Updated: 2025/01/06 15:47:41 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_conversion(const char descripteur, va_list args)
{
	int	length;

	length = 0;
	if (descripteur == 'c')
		length += print_c(va_arg(args, int));
	if (descripteur == 's')
		length += print_s(va_arg(args, char *));
	if (descripteur == 'p')
		length += print_p(va_arg(args, unsigned long long));
	if (descripteur == 'd' || descripteur == 'i')
		length += print_int(va_arg(args, int));
	if (descripteur == 'u')
		length += print_u(va_arg(args, unsigned int));
	if (descripteur == 'x' || descripteur == 'X')
		length += print_hexa(va_arg(args, unsigned int), descripteur);
	if (descripteur == '%')
		length += print_percent();
	return (length);
}

int	ft_printf(const char *arg0, ...)
{
	va_list	args;
	size_t	i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, arg0);
	while (arg0[i] != '\0')
	{
		if (arg0[i] == '%')
		{
			length += print_conversion(arg0[i + 1], args);
			i += 2;
		}
		else
		{
			write(1, &arg0[i], 1);
			length++;
			i++;
		}
	}
	return (length);
}
