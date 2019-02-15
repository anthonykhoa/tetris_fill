/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:58:09 by anttran           #+#    #+#             */
/*   Updated: 2019/01/08 16:58:11 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	upperleft(t_tet *tet)
{
	int	i;
	int	minx;
	int	miny;

	while (tet)
	{
		minx = min(tet->x, 4);
		miny = min(tet->y, 4);
		i = -1;
		while (++i < SIZE)
		{
			tet->x[i] -= minx;
			tet->y[i] -= miny;
		}
		tet = tet->next;
	}
}

static char	**new_map(int size)
{
	char	**map;
	int		row;
	int		col;

	row = -1;
	map = malloc(sizeof(char*) * size);
	while (++row < size)
	{
		col = 0;
		map[row] = (char*)ft_memalloc(size + 1);
		while (col < size)
			map[row][col++] = EMPTY;
	}
	return (map);
}

char		**solve(t_tet *tet)
{
	char	**map;
	int		size;

	if (!tet)
		return (NULL);
	size = ft_sqrt(g_num_tets * SIZE);
	map = new_map(size);
	upperleft(tet);
	while (!real_solver(tet, map, size))
	{
		ft_strdel(map);
		map = new_map(++size);
	}
	return (map);
}
