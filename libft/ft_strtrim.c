/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 14:54:23 by azineddi          #+#    #+#             */
/*   Updated: 2018/10/24 19:02:35 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_trim_copy(char *src, char const *s, size_t i, size_t z)
{
	size_t k;

	k = 0;
	while (k < z)
	{
		src[k] = s[i];
		k++;
		i++;
	}
	src[k] = '\0';
}

char			*ft_strtrim(char const *s)
{
	char	*str_mem;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i == ft_strlen(s))
	{
		if (!(str_mem = (char*)malloc(1)))
			return (NULL);
		str_mem[0] = '\0';
		return (str_mem);
	}
	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	str_mem = ft_strnew(j - i + 1);
	if (!str_mem)
		return (NULL);
	ft_trim_copy(str_mem, s, i, j - i + 1);
	return (str_mem);
}
