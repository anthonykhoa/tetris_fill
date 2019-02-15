/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:57:44 by anttran           #+#    #+#             */
/*   Updated: 2019/01/14 19:04:19 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	print_map(char **map)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(map[0]))
		ft_putendl(map[i++]);
}

int			main(int argc, char **argv)
{
	int		fd;
	char	**map;
	t_tet	*tet;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			ft_putendl("error");
		else if ((map = validate_tets(fd)) && map[0][0] &&
				!map[g_num_tets - 1][20])
		{
			tet = create_tets(map);
			print_map(solve(tet));
			free(tet);
			ft_strdel(map);
		}
		else
			ft_putendl("error");
		close(fd);
	}
	else
		ft_putendl("usage: ./fillit [tetrominos_file]");
}
