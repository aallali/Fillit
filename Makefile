# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aallali <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/17 21:24:40 by aallali           #+#    #+#              #
#    Updated: 2018/12/20 22:05:25 by aallali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fillit
LIBFTC = libft/*.c
LIBFTO = *.o
LIBFTA = libft/libft.a
FLAG = -Wall -Wextra -Werror

all: $(NAME)


$(NAME): $(OBJECTS)
	gcc  $(FLAG) -c $(LIBFTC) libft/libft.h
	ar rc libft/libft.a $(LIBFTO)
	gcc $(FLAG) *.c $(LIBFTA) -o $(NAME)
	
clean: 
	/bin/rm -f $(LIBFTO)
	/bin/rm -f libft/libft.h.gch
	/bin/rm -f .solver.c.swp
fclean: clean 
	/bin/rm -f $(LIBFTA)
	/bin/rm -f $(NAME)
re: fclean all
