/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:13:41 by azineddi          #+#    #+#             */
/*   Updated: 2018/10/25 11:47:04 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)(dst))[i] = ((unsigned char*)(src))[i];
		if (((unsigned char*)(src))[i] == (unsigned char)c)
			return ((unsigned char*)dst + i + 1);
		i++;
	}
	return (NULL);
}
