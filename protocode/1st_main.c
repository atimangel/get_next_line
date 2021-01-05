/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 13:19:23 by snpark            #+#    #+#             */
/*   Updated: 2020/12/31 15:24:19 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		main(void)
{
	ssize_t fd;
	char	*line;
	char	buf[BUFFER_SIZE];
	int		read_num;
	char	c;
	int		i;

	line = 0;
	i = 0;
	fd = open("text.txt", O_RDONLY);
	while ((read_num = read(fd, &c, 1)) == 1 && i < BUFFER_SIZE)
	{
		if (c != '\n')
			buf[i++] = c;
		if (c == '\n' || i == BUFFER_SIZE)
		{
			printf("%s%d\n", buf, i);
			while (i > 0)
				buf[--i] = 0;
		}
	}
	return (0);
}
