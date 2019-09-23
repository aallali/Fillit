/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 19:54:02 by aallali           #+#    #+#             */
/*   Updated: 2018/12/20 21:59:42 by aallali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	to_zero(int *i, int *j, int *x)
{
	*i = 0;
	*j = 0;
	*x = 0;
}

int		check_connection(char *str)
{
	int block;
	int i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				block++;
		}
		i++;
	}
	return (block == 6 || block == 8);
}

int		check_counts(char *str, int count)
{
	int i;
	int blocs;

	blocs = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && ++blocs > 4)
				return (2);
		}
		else if (str[i] != '\n')
			return (3);
		i++;
	}
	if (count == 21 && str[20] != '\n')
		return (4);
	if (!check_connection(str))
		return (5);
	return (0);
}

int		read_tetris(int fd, int count)
{
	char	buf[22];
	int		ret;
	int		oldret;

	oldret = 0;
	while ((ret = read(fd, buf, 21)) > 0)
	{
		oldret = ret;
		buf[ret] = '\0';
		if ((ret != 21 && ret != 20) || check_counts(buf, ret) != 0)
		{
			ft_putendl("error");
			return (0);
		}
		count++;
	}
	if (count >= 27 || oldret != 20)
	{
		ft_putendl("error");
		return (0);
	}
	return (count);
}

void	backtrack(int fd, int count)
{
	int			size;
	int			i;
	char		**board;
	t_tet		tetris[26];

	i = 0;
	size = ft_sqrt(count * 4);
	board = (char **)malloc(sizeof(char *) * 20);
	while (i < 20)
		board[i++] = (char *)malloc(sizeof(char) * 20);
	take_tetri(count, fd, tetris);
	malloc_struct(count, tetris);
	ft_create_workspace(board, 16);
	creat_wokspace(board, size);
	count_details(tetris, count);
	solver(board, tetris, size, count);
	free(board);
}
