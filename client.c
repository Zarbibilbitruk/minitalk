/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:11:14 by tautin--          #+#    #+#             */
/*   Updated: 2024/12/18 17:55:20 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_len(int pid, int len)
{
	int	i;

	i = 0;
	write(1, "l", 1);
	while (i < 32)
	{
		if (len & (1 << i))
		{
			kill(pid, SIGUSR1);
			write(1, "1", 1);
		}
		else
		{
			kill(pid, SIGUSR2);
			write(1, "0", 1);
		}
		i++;
		usleep(500);
	}
}

void	send_msg(int pid, const char *str)
{
	int				i;
	int				index;

	i = 0;
	while (str[i])
	{
		write(1, "m", 1);
		index = 0;
		while (index < 8)
		{
			if (str[i] & (1 << index))
			{
				kill(pid, SIGUSR1);
				write(1, "1", 1);
			}
			else
            {
				kill(pid, SIGUSR2);
				write(1, "0", 1);
			}
			index++;
			usleep(500);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int			pid;
	int			i;
	const char	*msg;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (!pid || pid <= 5)
			return (printf("PID incorrect"));
		msg = av[2];
		if (!msg)
			return (printf("Erreur avec le message"));
		send_len(pid, strlen(msg));
		send_msg(pid, msg);
	}
	else
		return (printf("Erreur format, entrez:\n\t./client <PID> <message>"));
}
