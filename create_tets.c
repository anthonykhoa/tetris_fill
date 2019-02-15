/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:57:56 by anttran           #+#    #+#             */
/*   Updated: 2019/01/14 17:52:37 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tet	*new_tets(int size)
{
	int		i;
	t_tet	*new;
	t_tet	*head;
	char	letter;

	i = 1;
	letter = 'A';
	new = malloc(sizeof(t_tet));
	new->letter = letter++;
	head = new;
	while (i++ < size)
	{
		new->next = malloc(sizeof(t_tet));
		new->next->letter = letter++;
		new = new->next;
	}
	new = NULL;
	return (head);
}

static t_tet	*make_tets(char ***fullmap, t_tet *tet,
		int row, int col)
{
	int		i;
	int		set;
	t_tet	*head;

	i = -1;
	head = tet;
	while (++i < g_num_tets)
	{
		set = 0;
		row = -1;
		while (++row < SIZE)
		{
			col = -1;
			while (++col < SIZE)
			{
				(fullmap[i][row][col] == BLOCK) ? (tet->x[set] = col) : 0;
				(fullmap[i][row][col] == BLOCK) ? (tet->y[set++] = row) : 0;
			}
		}
		tet->width = max(tet->x, 4) - min(tet->x, 4) + 1;
		tet->height = max(tet->y, 4) - min(tet->y, 4) + 1;
		tet = tet->next;
	}
	return (head);
}

t_tet			*create_tets(char **map)
{
	int		row;
	int		col;
	int		i;
	char	***fullmap;
	t_tet	*tet;

	i = -1;
	row = 0;
	col = 0;
	tet = new_tets(g_num_tets);
	fullmap = malloc(sizeof(char**) * g_num_tets);
	while (++i < g_num_tets)
		fullmap[i] = ft_strsplit(map[i], '\n');
	return (make_tets(fullmap, tet, row, col));
}
