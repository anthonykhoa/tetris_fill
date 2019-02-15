/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:44:27 by anttran           #+#    #+#             */
/*   Updated: 2019/01/08 16:50:18 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft/libft.h"

# define EMPTY '.'
# define BLOCK '#'
# define SIZE 4

int	g_num_tets;

typedef struct		s_tet
{
	char			letter;
	int				x[4];
	int				y[4];
	int				width;
	int				height;
	struct s_tet	*next;
}					t_tet;

char				**validate_tets(int fd);
t_tet				*create_tets(char **map);
int					real_solver(t_tet *tet, char **map, int size);
char				**solve(t_tet *tet);

#endif
