/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 13:13:08 by snpark            #+#    #+#             */
/*   Updated: 2021/01/07 17:47:28 by senoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 3

static int	sub_get(char **dest,char **src, char **save)
{
	*dest = ft_strjoin_free_s1(*dest, *src);
	if ((*save)[ft_strnewline(*src)] == '\n')
	{
		(*dest)[ft_strnewline(*dest)] = '\0';
		
		return (1);
	}
}

int		get_next_line(int fd, char **line)
{
	int		readnum;
	char		*buf;
	static char	*save;

	*line = (char *)malloc(1);
	**line = '\0';
	if (save && *save)
	{
		*line = ft_strjoin_free_s1(*line, save);
		if (save[ft_strnewline(save)] == '\n')
		{
			(*line)[ft_strnewline(*line)] = '\0';
			save = ft_substr_free_s(save, ft_strnewline(save) + 1, ft_strlen(save));
			return (1);
		}
		free(save);
	}
	buf = (char *)malloc(BUFFER_SIZE + 1);
	while ((readnum = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[readnum] = '\0';
		*line = ft_strjoin_free_s1(*line, buf);
		if (buf[ft_strnewline(buf)] == '\n')
		{
			(*line)[ft_strnewline(*line)] = '\0';
			save = ft_substr_free_s(buf, ft_strnewline(buf) + 1, BUFFER_SIZE);
			return (1);
		}
	}
	free(buf);
	return (readnum > 0 ? 1 : readnum);
}
