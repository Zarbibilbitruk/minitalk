/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:02:39 by tautin--          #+#    #+#             */
/*   Updated: 2025/01/06 19:21:24 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	next_step_struct(t_data *data)
{
	data->power = 1;
	data->value = 0;
	data->index_bit = 0;
	data->trigger--;
}

int	get_length(int signum, t_data *data)
{
	if (signum == SIGUSR1)
	{
		data->value += (1 * data->power);
		data->power *= 2;
	}
	else
		data->power *= 2;
	data->index_bit++;
	return (data->value);
}

char	*get_str(int signum, t_data *data)
{
	static char	*str;

	if (str == NULL)
	{
		str = malloc(sizeof(char) * data->length + 1);
		if (str == NULL)
			return (NULL);
	}
	if (signum == SIGUSR1)
	{
		data->value += (1 * data->power);
		data->power *= 2;
	}
	else
		data->power *= 2;
	data->index_bit++;
	if (data->index_bit == 8)
	{
		str[data->i] = data->value;
		data->value = 0;
		data->power = 1;
		data->i++;
		data->index_bit = 0;
	}
	return (str);
}

void	srv_signal_handler(int signum)
{
	static t_data	data = {0, NULL, 0, 1, 0, 1, 0};

	if (data.trigger == 1)
	{
		data.length = get_length(signum, &data);
		if (data.index_bit == 32)
			next_step_struct(&data);
	}
	else
	{
		data.str = get_str(signum, &data);
		if (data.i == data.length)
		{
			write(1, data.str, data.length);
			write(1, "\n", 1);
			data.trigger = 1;
			data.i = 0;
			data.str = NULL;
		}
	}
}

int	main(int argc, char **argv)
{
	if (!argv || argc > 1)
	{
		ft_printf("Pas d'argument autorise");
		return (1);
	}
	signal(SIGUSR1, srv_signal_handler);
	signal(SIGUSR2, srv_signal_handler);
	ft_printf("PID : %i\n", getpid());
	while (1)
		pause();
	return (0);
}
