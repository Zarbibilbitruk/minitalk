/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:46:45 by tautin--          #+#    #+#             */
/*   Updated: 2024/12/18 18:41:36 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reset(t_data *data)
{
	data->power = 1;
	data->char_actuel = 0;
	data->index_bit = 0;
}

int	handle_len(int signal_recu, t_data *data)
{
	if (signal_recu == SIGUSR1)
	{
		data->len += (1 * data->power);
		data->power *= 2;
		// write(1, "1", 1);
	}
	else
	{
		data->power *= 2;
		// write(1, "0", 1);
	}
	return (data->len);
}

char	*handle_str(int signal_recu, t_data *data)
{
	static char	*str;

	if(!str)
	{
		str = malloc(sizeof(char) * data->len + 1);
		if (!str)
			return (NULL);
	}
	if (signal_recu == SIGUSR1)
	{
		data->char_actuel += (1 * data->power);
		data->power *= 2;
	}
	else
		data->power *= 2;
	data->index_bit++;
	if (data->index_bit == 8)
	{
		str[data->i] = data->char_actuel;
		data->char_actuel = 0;
		data->power = 1;
		data->i++;
		data->index_bit = 0;
	}
	return (str);
}

void	handle_sig(int signal_recu)
{
	static t_data	data = {0, NULL, 0, 0, 1, 0};
	static int	trigger = 1;

	if (trigger == 1)
	{
		handle_len(signal_recu, &data);
		if (data.index_bit == 31)
		{
			reset(&data);
			trigger--;
		}
	}
	if (trigger == 0)
	{
		data.str = handle_str(signal_recu, &data);
		if(data.i == data.len)
		{
			printf("%s\n", data.str);
			trigger = 1;
			data.i = 0;
			data.str = NULL;
		}
	}
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
