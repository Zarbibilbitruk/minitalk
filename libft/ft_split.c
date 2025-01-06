/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tautin-- <tautin--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:20:15 by tautin--          #+#    #+#             */
/*   Updated: 2024/06/06 16:25:19 by tautin--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_str(char const *s, char c)
{
	int		i;
	size_t	nbr;

	if (!s)
		return (0);
	i = 0;
	nbr = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			nbr++;
		while (s[i] != c && s[i])
			i++;
	}
	return (nbr);
}

static size_t	another_len(char const *s, char c)
{
	size_t	len;

	if (ft_strchr(s, c) == NULL)
		len = ft_strlen(s);
	else
		len = ft_strchr(s, c) - s;
	return (len);
}

static char	**ft_free(char	**tab, int j)
{
	while (j >= 0)
	{
		free (tab[j]);
		j--;
	}
	free (tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	string_len;
	int		j;

	tab = (char **)malloc((count_str(s, c) + 1) * sizeof(char *));
	if (!tab || !s)
		return (NULL);
	j = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			string_len = another_len(s, c);
			tab[j++] = ft_substr(s, 0, string_len);
			if (tab[j - 1] == NULL)
				return (ft_free(tab, j - 2));
			s += string_len;
		}
	}
	tab[j] = NULL;
	return (tab);
}
