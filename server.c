/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:46:45 by tautin--          #+#    #+#             */
/*   Updated: 2024/12/16 19:27:58 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signa, siginfo_t *info, )
{
	
}

int	main(void)
{
	printf("PID : %d\n", getpid());

	Signal(SIGUSR1, handler); //a faire

	while (1)
		pause();
	return (EXIT_SUCCESS);
}
