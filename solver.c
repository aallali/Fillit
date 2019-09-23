/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:36:28 by aallali           #+#    #+#             */
/*   Updated: 2018/12/19 20:11:06 by aallali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_board(char **board, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			ft_putchar(board[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

int		solve(char **board, t_tet *tetris, int *sc, int c)
{
	int it[2];

	it[0] = 0;
	it[1] = 0;
	if (c == sc[1])
		return (1);
	while (it[0] < sc[0] - tetris[c].height + 1)
	{
		while (it[1] < sc[0] - tetris[c].weight + 1)
		{
			if (check_put_tetri(board, it[0], it[1], tetris[c]) == 1)
			{
				put_tetri(board, it[0], it[1], tetris[c]);
				if (solve(board, tetris, sc, c + 1) == 1)
					return (1);
				else
					delete_tetris(board, tetris[c]);
			}
			it[1]++;
		}
		it[1] = 0;
		it[0]++;
	}
	c++;
	return (0);
}

int		solver(char **board, t_tet *tetris, int size, int count)
{
	int it[2];

	it[0] = size;
	it[1] = count;
	if (!solve(board, tetris, it, 0))
	{
		it[0]++;
		creat_wokspace(board, it[0]);
		return (solver(board, tetris, it[0], it[1]));
	}
	print_board(board, it[0]);
	return (0);
}

void	count_details(t_tet *tetris, int count)
{
	int x;
	int i;
	int height;
	int weight;

	height = 0;
	weight = 0;
	x = 0;
	i = 0;
	while (i < count)
	{
		while (x < 4)
		{
			if (tetris[i].tet_coord[x][0] >= height)
				tetris[i].height = tetris[i].tet_coord[x][0];
			if (tetris[i].tet_coord[x][1] >= weight)
				tetris[i].weight = tetris[i].tet_coord[x][1];
			x++;
		}
		x = 0;
		i++;
	}
}

int		ft_sqrt(int nbr)
{
	int size;

	size = 2;
	while (size * size < nbr)
		size++;
	return (size);
}
