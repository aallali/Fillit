/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 10:48:26 by azineddi          #+#    #+#             */
/*   Updated: 2018/10/23 14:56:26 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	if (i == 0)
		return (NULL);
	while (s[i] != (char)c && i >= 0)
		i--;
	if (i == -1)
		return (NULL);
	return ((char*)s + i);
}
