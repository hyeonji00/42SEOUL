/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:12:18 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/05/20 16:02:26 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *buf, char *save)
{
	int		idx;
	char	*tmp;

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
	return (save);
}

static char	*update_save(char *line)
{
	int		i;
	char	*result;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (0);
	result = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (result == 0)
		return (0);
	if (result[0] == '\0')
	{
		free(result);
		result = 0;
		return (0);
	}
	line[i + 1] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == 0)
		return (0);
	line = read_line(fd, buf, save);
	free(buf);
	buf = 0;
	if (line == 0)
		return (0);
	save = update_save(line);
	return (line);
}
