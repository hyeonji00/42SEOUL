/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 09:48:54 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/06/04 10:41:07 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd[4];
	char	*line;

	fd[0] = open("test/file", O_RDONLY);
	if (fd[0] < 1)
	{
		printf("\nERROR in OPEN\n");
		return (0);
	}
	fd[1] = open("test/file2", O_RDONLY);
	if (fd[1] < 1)
	{
		printf("\nERROR in OPEN\n");
		return (0);
	}
	line = 0;
	while (1)
	{
		line = get_next_line(fd[0]);
		if (line != 0)
		{
			printf("%s", line);
		}
		if (line == 0)
			break ;
		line = get_next_line(fd[1]);
		if (line != 0)
		{
			printf("%s", line);
		}
		if (line == 0)
			break ;
	}
	free(line);
	close(fd[0]);
	close(fd[1]);
}
