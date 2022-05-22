/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:12:18 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/05/22 22:51:57 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static char	*read_line(int fd, char *save)
{
	char	*buf;
	int		idx;
	char	*tmp;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == 0)
		return (0);
	idx = 0;
	while (save == 0 || ft_strchr(save, '\n') == 0)
	{
		idx = read(fd, buf, BUFFER_SIZE);
		if (idx <= 0)
			break ;
		buf[idx] = '\0';
		tmp = save;
		save = ft_strjoin(save, buf);
		if (save == 0)
			return (0);
		free(tmp);
		tmp = 0;
	}
	free(buf);
	buf = 0;
	return (save);
}

static char	*update_save(char *line)
{
	char	*update;
	int		i;
	int		start;
	int		end;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (0);
	start = i + 1;
	end = ft_strlen(line) - i;
	update = ft_substr(line, start, end);
	if (update == 0)
		return (0);
	if (update[0] == '\0')
	{
		free(update);
		update = 0;
		return (0);
	}
	line[i + 1] = '\0';
	return (update);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	line = read_line(fd, save);
	if (line == 0)
		return (0);
	save = update_save(line);
	return (line);
}
