/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:46:45 by tautin--          #+#    #+#             */
/*   Updated: 2024/12/18 15:36:07 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_len(int signal_recu, int index_bit, int *len)
{
	static int	power = 1;

	if (signal_recu == SIGUSR1)
	{
		*len += (1 * power);
		power *= 2;
	}
	else
	{
		power *= 2;
	}
	if (index_bit == 31)
		power = 1;
}

void	handle_str(int signal_recu, char *str, int *len, int *trigger)
{
	static int				i = 0;
	static unsigned char	char_actuel = 0;
	static int				index_bit = 0;

	char_actuel |= (signal_recu == SIGUSR1);
	if (index_bit == 8)
	{
		str[i] = char_actuel;
		index_bit = 0;
		char_actuel = 0;
		i++;
	}
	else
		char_actuel <<= 1;
	index_bit++;
	if (i == *len)
	{
		str[i] = '\0';
		write(1, str, *len);
		i = 0;
		// *len = 0;
		str = NULL;
		*trigger = 1;
	}
}

void	handle_sig(int signal_recu)
{
	static int	trigger = 1;
	static int	len = 0;
	static char	*str = NULL;
	static int	index_bit = 0;

	if (trigger == 1)
	{
		handle_len(signal_recu, index_bit, &len);
		if (index_bit == 31)
		{
			trigger--;
			index_bit = 0;
		}
		index_bit++;
	}
	if(!str)
	{
		str = malloc(sizeof(char) * len + 1);
		if (!str)
			exit(EXIT_FAILURE);
	}
	if (trigger == 0)
		handle_str(signal_recu, str, &len, &trigger);
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
