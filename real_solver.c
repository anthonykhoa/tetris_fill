/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:57:51 by anttran           #+#    #+#             */
/*   Updated: 2019/01/14 17:57:42 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	set_tets(t_tet *tet, char **map, int y, int x)
{
	int	i;

	i = -1;
	while (++i < SIZE)
		map[y + tet->y[i]][x + tet->x[i]] = tet->letter;
}

static int	check_place(t_tet *tet, char **map, int y, int x)
{
	int	i;
	int	c;

	c = 0;
	i = -1;
	while (++i < SIZE)
		if (map[y + tet->y[i]][x + tet->x[i]] == EMPTY)
			c++;
	return (c == SIZE ? 1 : 0);
}

int			real_solver(t_tet *tet, char **map, int size)
{
	int		x;
	int		y;
	char	letter;

	if (!tet)
		return (1);
	y = -1;
	letter = tet->letter;
	while (++y <= (size - tet->height))
	{
		x = -1;
		while (++x <= (size - tet->width))
			if (check_place(tet, map, y, x))
			{
				set_tets(tet, map, y, x);
				if (real_solver(tet->next, map, size))
					return (1);
				tet->letter = EMPTY;
				set_tets(tet, map, y, x);
				tet->letter = letter;
			}
	}
	return (0);
}
