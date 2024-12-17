/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:46:45 by tautin--          #+#    #+#             */
/*   Updated: 2024/12/17 20:47:23 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	handle_len(signal_recu)
{
	static int	index_bit;
	int			len;
	int			i;

	index_bit = 0;
	len = 0;
	i = 1;
	while (index_bit < 32)
	{
		if (signal_recu == SIGUSR1)
		{
			len += (1 * i);
			i *= 2;
		}
		else
			i *= 2;
		index_bit++;
	}
	return (len);
}

void	handle_str(int signal_recu, int len, char *str)
{
	static int				i;
	static unsigned char	char_actuel;
	static int				index_bit;

	i = 0;
	while (i < len)
	{
		char_actuel |= (signal_recu == SIGUSR1);
		index_bit++;
		if (index_bit == 8)
		{
			str[i] = char_actuel;
			index_bit = 0;
			char_actuel = 0;
		}
		else
			char_actuel <<= 1;
		i++;
	}
	str[i] = '\0';
	printf("%s", str);
}

void	handle_sig(int signal_recu)
{
	static int	trigger;
	int			len;
	char		*str;

	trigger = 1;
	len = 0;
	if (trigger == 1)
	{
		len = handle_len(signal_recu);
		trigger--;
	}
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		exit(EXIT_FAILURE);
	if (trigger == 0)
		handle_str(signal_recu, len, str);
}

int	main(void)
{
	printf("PID : %d\n", getpid());
	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
