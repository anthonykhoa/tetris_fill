/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:58:14 by anttran           #+#    #+#             */
/*   Updated: 2019/01/14 17:44:38 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	valid_char(char *tet)
{
	int		i;
	int		height;
	int		blocks;
	int		empty;

	i = -1;
	blocks = 0;
	empty = 0;
	height = 0;
	while (++i < 20)
	{
		(tet[i] == EMPTY) ? empty++ : 0;
		(tet[i] == BLOCK) ? blocks++ : 0;
		(tet[i] == '\n') ? height++ : 0;
	}
	return ((empty == 12 && height == SIZE &&
			blocks == SIZE && (tet[i] == '\n' || tet[i] == '\0')) ? 1 : 0);
}

static int	valid_touch(char **tet)
{
	int	cnt;
	int	row;
	int	col;

	cnt = 0;
	row = -1;
	col = -1;
	while (++row < SIZE)
	{
		col = -1;
		while (++col < SIZE)
		{
			if (tet[row][col] == BLOCK && row < 3)
				tet[row + 1][col] == BLOCK ? cnt++ : 0;
			if (tet[row][col] == BLOCK && row > 0)
				tet[row - 1][col] == BLOCK ? cnt++ : 0;
			if (tet[row][col] == BLOCK && col < 3)
				tet[row][col + 1] == BLOCK ? cnt++ : 0;
			if (tet[row][col] == BLOCK && col > 0)
				tet[row][col - 1] == BLOCK ? cnt++ : 0;
		}
	}
	return (cnt == 6 || cnt == 8 ? 1 : 0);
}

char		**validate_tets(int fd)
{
	int		i;
	int		height;
	char	**map;

	i = 0;
	height = -1;
	map = malloc(sizeof(char*) * 26);
	while (i < 26)
	{
		map[i] = (char*)ft_memalloc(21);
		if (!(read(fd, map[i], 21)))
			return (map);
		if (!valid_char(map[i]) || !valid_touch(ft_strsplit(map[i], '\n')))
			return (NULL);
		g_num_tets = ++i;
	}
	return (NULL);
}
