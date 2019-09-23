/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:21:31 by aallali           #+#    #+#             */
/*   Updated: 2018/12/19 20:28:06 by aallali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# define RSET(x) if(x == 1) break;

typedef	struct	s_tetriminos
{
	char		l;
	int			tet_coord[4][2];
	int			height;
	int			weight;
}				t_tet;

void			to_zero(int *i, int *j, int *x);
int				read_tetris(int fd, int count);
int				check_counts(char *str, int count);
int				check_connection(char *str);
void			malloc_struct(int count, t_tet *tetris);
void			take_tetri(int count, int fd, t_tet *tetris);
void			creat_wokspace(char **board, int size);
void			ft_create_workspace(char	**board, int lenght);
int				check_put_tetri(char **board, int x, int y, t_tet tetris);
void			delete_tetris(char **board, t_tet tetris);
void			print_board(char **board, int size);
int				solve(char **board, t_tet *tetris, int *sc, int c);
int				solver(char **board, t_tet *tetris, int size, int count);
void			count_details(t_tet *tetris, int count);
int				ft_sqrt(int nbr);
void			to_zero(int *i, int *j, int *x);
int				up_count(char **tab);
int				left_count(char **tab);
void			move_tetris_up(char **str, int x, int i, int j);
void			move_tetris_left(char **st, int x, int i, int j);
void			move_tetris(char **tab);
void			backtrack(int fd, int count);
void			put_tetri(char **board, int x, int y, t_tet tetris);
#endif
