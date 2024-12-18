/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:11:14 by tautin--          #+#    #+#             */
/*   Updated: 2024/12/18 15:24:55 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_len(int pid, int len)
{
	int	i;

	i = 0;

	while (i < 32)
	{
		if (len & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(100);
	}
}

void	send_msg(int pid, const char *str)
{
	int				i;
	int				index;
	unsigned char	temp;

	i = 0;
	while (str[i])
	{
		index = 8;
		temp = str[i];
		while (index > 0)
		{
			index--;
			if ((temp >> index) & 1)
				kill(pid, SIGUSR1);
			else
                kill(pid, SIGUSR2);
			usleep(100);
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
