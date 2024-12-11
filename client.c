/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:11:14 by tautin--          #+#    #+#             */
/*   Updated: 2024/12/11 19:31:03 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	int		id;
	char	*msg;

	if (ac == 3)
	{
		id = ft_atoi(av[1]);
		if (!id)
			return (ft_putstr_fd(message derreur));
		msg = av[2];
		if (!msg)
			return (ft_putstr_fd(message derreur));
		send_msg(msg); // a faire
	}
	return (ft_putstr_fd(message derreur)); // a faire
}