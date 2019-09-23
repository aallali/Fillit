/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tache1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:14:12 by aallali           #+#    #+#             */
/*   Updated: 2018/12/19 20:14:14 by aallali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	creat_wokspace(char **board, int size)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < size)
	{
		while (j < size)
		{
			board[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_create_workspace(char **board, int lenght)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	board = (char **)malloc(sizeof(char *) * 16);
	while (i < 16)
		board[i++] = (char *)malloc(sizeof(char) * 16);
	i = 0;
	while (i < lenght)
	{
		while (j < lenght)
		{
			board[i][j] = '$';
			j++;
		}
		j = 0;
		i++;
	}
}

int		check_put_tetri(char **board, int x, int y, t_tet tetris)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (board[x + tetris.tet_coord[i][0]]
				[y + tetris.tet_coord[i][1]] != '.')
			return (0);
		i++;
	}
	return (1);
}

void	put_tetri(char **board, int x, int y, t_tet tetris)
{
	int i;

	i = 0;
	while (i < 4)
	{
		board[x + tetris.tet_coord[i][0]]
			[y + tetris.tet_coord[i][1]] = tetris.l;
		i++;
	}
}

void	delete_tetris(char **board, t_tet tetris)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 16)
	{
		while (j < 16)
		{
			if (board[i][j] == tetris.l)
				board[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
}
