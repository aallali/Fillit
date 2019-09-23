/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 17:05:28 by azineddi          #+#    #+#             */
/*   Updated: 2018/10/25 19:29:00 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char *pattern;
	const char *begin;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		begin = haystack;
		pattern = needle;
		while (*haystack && *pattern && *haystack == *pattern)
		{
			haystack++;
			pattern++;
		}
		if (*pattern == '\0')
			return ((char*)begin);
		haystack = begin + 1;
	}
	if (haystack[0] == '\0' && needle[0] == '\0')
		return ("");
	return (0);
}
