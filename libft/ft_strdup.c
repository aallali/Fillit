/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:28:59 by azineddi          #+#    #+#             */
/*   Updated: 2018/11/13 12:03:41 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		length;
	char	*out;

	length = (int)ft_strlen(s1);
	i = 0;
	out = NULL;
	out = (char*)malloc(sizeof(char) * length + 1);
	if (!out)
		return (NULL);
	while (i < length)
	{
		out[i] = s1[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
