/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tache2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:14:18 by aallali           #+#    #+#             */
/*   Updated: 2018/12/19 20:14:21 by aallali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	extract_xy(char **tab, int xy[4][2])
{
	int x;
	int i;
	int j;

	to_zero(&i, &x, &j);
	while (x < 4)
	{
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
			{
				xy[x][0] = i;
				xy[x][1] = j;
				x++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	malloc_struct(int count, t_tet *tetris)
{
	char	c;
	int		i;

	i = 0;
	c = 'A';
	while (i < count)
	{
		tetris[i].l = c;
		i++;
		c++;
	}
}

void	do_move_extract(char **tetri, int xy[4][2])
{
	move_tetris(tetri);
	extract_xy(tetri, xy);
}

void	take_tetri(int count, int fd, t_tet *tetris)
{
	char	*line;
	char	**tetri;
	int		xy[4][2];
	int		tnt[3];

	to_zero(&tnt[0], &tnt[1], &tnt[2]);
	tetri = (char **)malloc(sizeof(char *) * 4);
	while (tnt[1] < count)
	{
		while (tnt[2] < 4)
		{
			get_next_line(fd, &line);
			tetri[tnt[2]++] = ft_strdup(line);
		}
		do_move_extract(tetri, xy);
		while (tnt[0] < 4)
		{
			tetris[tnt[1]].tet_coord[tnt[0]][0] = xy[tnt[0]][0];
			tetris[tnt[1]].tet_coord[tnt[0]][1] = xy[tnt[0]][1];
			tnt[0]++;
		}
		to_zero(&tnt[0], &tnt[2], &tnt[0]);
		get_next_line(fd, &line);
		tnt[1]++;
	}
}
