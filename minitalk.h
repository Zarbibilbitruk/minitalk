/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:11:41 by tautin--          #+#    #+#             */
/*   Updated: 2024/12/18 18:39:52 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_data
{
	int		len;
	char	*str;
	int		index_bit;
	int		char_actuel;
	int		power;
	int		i;
}			t_data;

/*** fonctions ***/
int		ft_atoi(const char *nptr);
void	ft_putstr_fd(char *s, int fd);

#endif