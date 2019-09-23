/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_adjust.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 00:34:19 by aallali           #+#    #+#             */
/*   Updated: 2018/12/19 00:37:22 by aallali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		up_count(char **tab)
{
	int x;
	int count;

	count = 0;
	x = 0;
	while (x < 4)
	{
		if (ft_strchr(tab[x], '#') == NULL)
			count++;
		else
			break ;
		x++;
	}
	return (count);
}

int		left_count(char **tab)
{
	int intg[4];

	to_zero(&intg[0], &intg[1], &intg[2]);
	intg[3] = 0;
	while (intg[0] < 4)
	{
		while (intg[1] < 4)
		{
			if (tab[intg[1]][intg[0]] != '#')
				intg[2]++;
			intg[1]++;
		}
		intg[1] = 0;
		if (intg[2] == 4)
			intg[3]++;
		else
			break ;
		intg[2] = 0;
		intg[0]++;
	}
	return (intg[3]);
}

void	move_tetris_up(char **tab, int i, int j, int x)
{
	int c;

	c = up_count(tab);
	while (x < c)
	{
		while (i < 4)
		{
			while (j < 4)
			{
				if (tab[i][j] == '#' && i != 0)
				{
					tab[i][j] = '.';
					tab[i - 1][j] = '#';
				}
				j++;
			}
			j = 0;
			i++;
		}
		i = 0;
		x++;
	}
}

void	move_tetris_left(char **tab, int x, int i, int j)
{
	int c;

	c = left_count(tab);
	while (x < c)
	{
		while (i < 4)
		{
			while (j < 4)
			{
				if (tab[i][j] == '#' && j != 0)
				{
					tab[i][j] = '.';
					tab[i][j - 1] = '#';
				}
				j++;
			}
			j = 0;
			i++;
		}
		i = 0;
		x++;
	}
}

void	move_tetris(char **tab)
{
	move_tetris_up(tab, 0, 0, 0);
	move_tetris_left(tab, 0, 0, 0);
}
