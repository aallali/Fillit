/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 10:36:31 by azineddi          #+#    #+#             */
/*   Updated: 2018/11/13 12:02:24 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (s[k] != '\0')
	{
		k++;
	}
	while (s[i] != c && i < k)
		i++;
	if (i == k && c == '\0')
		return ((char*)s + i);
	else if (i == k)
		return (NULL);
	else
		return ((char*)s + i);
}
