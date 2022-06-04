/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 09:48:54 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/06/04 10:24:39 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test/file", O_RDONLY);
	if (fd < 1)
	{
		printf("\nERROR in OPEN\n");
		return (0);
	}
	line = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line != 0)
		{
			printf("%s", line);
		}
		if (line == 0)
			break ;
	}
	free(line);
	close(fd);
}
