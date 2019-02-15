/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:55:59 by anttran           #+#    #+#             */
/*   Updated: 2018/12/02 15:55:34 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count_words(const char *s, char c)
{
	int sp;
	int sp_tmp;

	sp_tmp = 0;
	sp = 0;
	while (*s)
	{
		if (sp_tmp == 1 && *s == c)
			sp_tmp = 0;
		if (sp_tmp == 0 && *s != c)
		{
			sp_tmp = 1;
			sp++;
		}
		s++;
	}
	return (sp);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		start;

	if ((s == 0) || (c == 0) || (!(tab =
		ft_memalloc((sizeof(char *) * (ft_count_words(s, c) + 1))))))
		return (NULL);
	i = 0;
	j = -1;
	while (++j < ft_count_words(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		tab[j] = ft_strsub(s, start, i - start);
		i++;
	}
	return (tab);
}
