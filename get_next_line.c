/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 13:13:08 by snpark            #+#    #+#             */
/*   Updated: 2021/01/04 18:33:29 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t		ft_strnewline(char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}
/*
**find newline return index
**no newline? return end of the index
*/

static size_t	ft_strlen(char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	static char *save;
	int			num_read;
	int			i;

	i = -1;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	buf[BUFFER_SIZE] = '\0';
	num_read = read(fd, buf, BUFFER_SIZE);
	ft_strdup(*line, buf);
	if (num_read == 0)
		return (0);
	if (num_read == -1)
		return (-1);
	return (1);
}
