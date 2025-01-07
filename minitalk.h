/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:31:07 by tautin--          #+#    #+#             */
/*   Updated: 2025/01/07 16:47:24 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int		length;
	char	*str;
	int		index_bit;
	int		trigger;
	int		value;
	int		power;
	int		car;
	int		i;
}			t_data;

void		send_len(int len, int pid_srv);
void		send_msg(char *str, int pid_srv);

void		next_step_struct(t_data *data);
int			get_stuff(int signum, t_data *data);
void		get_str(int signum, t_data *data);
void		srv_signal_handler(int signum);

#endif