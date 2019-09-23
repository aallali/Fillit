/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:59:04 by azineddi          #+#    #+#             */
/*   Updated: 2018/10/25 13:06:07 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t l1;
	size_t l2;
	size_t max;

	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	max = (n > l2 ? l2 : n);
	while (i < max)
	{
		s1[l1 + i] = s2[i];
		i++;
	}
	s1[l1 + i] = '\0';
	return (s1);
}
