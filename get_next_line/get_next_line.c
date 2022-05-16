/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:12:18 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/05/16 18:08:35 by hyeonjik         ###   ########.fr       */
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

static char	*read_line(int fd, char *buf, char *save)
{
	char	*new_line;
	char	*tmp;
	int		idx;

	idx = 0;
	new_line = save;
	while (new_line == 0 || !ft_strchr(new_line, '\n'))
	{
		idx = read(fd, buf, BUFFER_SIZE);
		if (idx == -1)
			return (0);
		else if (idx == 0)
			break ;
		buf[idx] = '\0';
		if (save == 0)
			save = ft_strdup("");
		tmp = save;
		save = ft_strjoin(tmp, buf);
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

void	test()
{
	// 커밋 테스트
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
