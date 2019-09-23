/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:15:25 by aallali           #+#    #+#             */
/*   Updated: 2018/12/19 20:15:26 by aallali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char const *argv[])
{
	char	buf[2];
	int		fd;
	int		count;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || read(fd, buf, 1) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	if (fd != -1)
		close(fd);
	fd = open(argv[1], O_RDONLY);
	if ((count = read_tetris(fd, 0)) == 0)
		return (0);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	backtrack(fd, count);
	return (0);
}
