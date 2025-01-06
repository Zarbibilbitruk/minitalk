/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:37:33 by tautin--          #+#    #+#             */
/*   Updated: 2024/05/30 13:55:00 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trimmed_len(int *start, int *end, char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (set[j] == s1[*start])
				(*start)++;
			if (set[j] == s1[*end])
				(*end)--;
			j++;
		}
		i++;
	}
	if (*end - *start + 1 < 0)
		return (0);
	return (*end - *start + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	size_t	len_trim;
	char	*trimmed;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	len_trim = trimmed_len(&start, &end, s1, set);
	trimmed = malloc(sizeof(char) * (len_trim + 1));
	if (!trimmed)
		return (NULL);
	while (start <= end)
	{
		trimmed[i] = s1[start];
		i++;
		start++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
