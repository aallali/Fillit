/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 17:09:41 by azineddi          #+#    #+#             */
/*   Updated: 2018/10/24 14:19:03 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				i;
	unsigned int	number;
	int				isnegative;

	i = 0;
	number = 0;
	isnegative = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i
] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		isnegative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += (int)str[i] - '0';
		i++;
	}
	if (isnegative)
		return (-number);
	return (number);
}
