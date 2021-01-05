/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 13:13:08 by snpark            #+#    #+#             */
/*   Updated: 2020/12/31 17:50:45 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int		get_next_line(int fd, char **line)
{
	char		*buf;
	static char *tmp;
	int			read_return;

	i = 0;
	if (!(buf = (char *)malloc(BUFFER_SIZE)))
		return (-1);
	if (!(tmp = (char *)malloc(BUFFER_SIZE)))
		return (-1);
	ft_bzero((void *)buf, (size_t)BUFFER_SIZE);
	if (tmp)
	{
		end = ft_strchr(tmp, '\n');
		ft_strdup(buf, tmp, ft_strchr(tmp, '\n'));
		ft_memmove(tmp, ft_strchr(tmp, '\n'));
		if (tmp)
			return (1);
	}	
	read_return = read(fd, buf, 1)
	*line = buf;
	if (read_return == 0)
		return (0);
	if (read_return == -1)
		return (-1);
	return (1);
}
