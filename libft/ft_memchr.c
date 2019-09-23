/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 22:37:20 by azineddi          #+#    #+#             */
/*   Updated: 2018/10/25 12:14:11 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char*)s;
	i = 0;
	while (i < n)
		if (*ptr != (unsigned char)c)
		{
			ptr++;
			i++;
		}
		else
		{
			return (ptr);
		}
	return (NULL);
}
