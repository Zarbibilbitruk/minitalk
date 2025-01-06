/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:43:05 by tautin--          #+#    #+#             */
/*   Updated: 2025/01/06 19:10:06 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_len(int len, int pid_srv)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (len & (1 << i))
		{
			kill(pid_srv, SIGUSR1);
		}
		else
		{
			kill(pid_srv, SIGUSR2);
		}
		i++;
		usleep(100);
	}
}

void	send_msg(char *str, int pid_srv)
{
	int	i;
	int	y;

	i = 0;
	while (str[i])
	{
		y = 0;
		while (y < 8)
		{
			if (str[i] & (1 << y))
				kill(pid_srv, SIGUSR1);
			else
				kill(pid_srv, SIGUSR2);
			y++;
			usleep(100);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;
	char	*msg;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (!pid || pid <= 5)
			return (ft_printf("PID incorrect"));
		msg = av[2];
		if (!msg)
			return (ft_printf("Erreur avec le message"));
		send_len(ft_strlen(msg), pid);
		send_msg(msg, pid);
	}
	else
		return (ft_printf("Erreur format, entrez:\n\t./client <PID> <message>"));
}
