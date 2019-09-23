/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:24:15 by azineddi          #+#    #+#             */
/*   Updated: 2018/10/23 10:32:54 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	log_10(unsigned int n)
{
	return (n >= 1) ? 1 + log_10(n / 10) : 0;
}

char			*ft_itoa(int n)
{
	char			*str;
	int				num_of_digit;
	unsigned int	m;

	num_of_digit = 0;
	if (n < 0)
		num_of_digit++;
	m = (n < 0 ? -n : n);
	num_of_digit += log_10(m);
	str = ft_strnew(num_of_digit + 1);
	if (!str)
		return (NULL);
	str[num_of_digit] = '\0';
	if (m == 0)
		str[0] = '0';
	while (m > 0)
	{
		str[num_of_digit - 1] = m % 10 + '0';
		m = m / 10;
		num_of_digit--;
	}
	if (num_of_digit == 1)
		str[0] = '-';
	return (str);
}
