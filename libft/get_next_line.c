/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ge_next_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:32:14 by thalme            #+#    #+#             */
/*   Updated: 2019/11/11 13:55:56 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			next_line(char **s, char **line)
{
	char			*temp;
	size_t			i;

	i = 0;
	while ((*s)[i] != '\n' && (*s)[i] != '\0')
		i++;
	if ((*s)[i] == '\n')
	{
		if (!(*line = ft_strsub(*s, 0, i)))
			return (-1);
		if (!(temp = ft_strdup(&((*s)[i + 1]))))
			return (-1);
		free(*s);
		*s = temp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else
	{
		if (!(*line = ft_strsub(*s, 0, i)))
			return (-1);
		ft_strdel(s);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*str[FD];
	char			buf[BUFF_SIZE + 1];
	char			*temp;
	int				ret;

	if (fd < 0 || fd > FD || BUFF_SIZE < 1)
		return (-1);
	if (str[fd] != NULL && ft_strchr(str[fd], '\n'))
		return (next_line(&str[fd], line));
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(0);
		temp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (ret == 0 && str[fd] == NULL)
		return (0);
	return (next_line(&(str[fd]), line));
}
