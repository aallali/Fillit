/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:22:11 by azineddi          #+#    #+#             */
/*   Updated: 2018/10/25 19:33:17 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t lh;
	size_t ln;
	size_t j;

	i = 0;
	lh = ft_strlen(haystack);
	ln = ft_strlen(needle);
	if (ln == 0)
		return ((char*)haystack);
	while (i + ln <= lh && i + ln <= len)
	{
		j = 0;
		while (j < ln)
		{
			if (haystack[i + j] != needle[j])
				break ;
			j++;
		}
		if (j == ln)
			return ((char*)haystack + i);
		i++;
	}
	return (NULL);
}
