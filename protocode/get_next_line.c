/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 13:13:08 by snpark            #+#    #+#             */
/*   Updated: 2020/12/31 15:54:16 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char	*buf;
	char	c;
	int		i;
	int		read_return;

	i = 0;
	if (!(buf = (char *)malloc(BUFFER_SIZE)))
		return (-1);
	ft_bzero((void *)buf, (size_t)BUFFER_SIZE);
	while (i < BUFFER_SIZE && (read_return = read(fd, &c, 1)) == 1 && c != '\n')
		buf[i++] = c;
	*line = buf;
	if (read_return == 0)
		return (0);
	if (read_return == -1)
		return (-1);
	return (1);
}
