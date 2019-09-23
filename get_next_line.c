/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:11:37 by aallali           #+#    #+#             */
/*   Updated: 2018/11/26 16:09:38 by aallali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		fillit_line(char **s, char **line, int fd, int ret)
{
	char	*tmp;
	int		len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		tmp = ft_strdup(s[fd] + len + 1);
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int		checkerror(int fd, char **line)
{
	if (fd == -1 || line == NULL)
		return (-1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*holder[465];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (checkerror(fd, line) == -1)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (holder[fd] == NULL)
			holder[fd] = ft_strnew(1);
		tmp = ft_strjoin(holder[fd], buf);
		free(holder[fd]);
		holder[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (holder[fd] == NULL || holder[fd][0] == '\0'))
		return (0);
	return (fillit_line(holder, line, fd, ret));
}
