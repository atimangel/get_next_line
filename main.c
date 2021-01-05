/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 13:19:23 by snpark            #+#    #+#             */
/*   Updated: 2021/01/04 18:28:24 by snpark           ###   ########.fr       */
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

	line = 0;
	fd = open("text.txt", O_RDONLY);
	while ((get_next_line(fd, &line) == 1))
	{
		printf("#1 %s!", line);
		free(line);
		printf("#2 %s?", line);
	}
	return (0);
}
