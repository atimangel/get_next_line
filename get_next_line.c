/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 13:13:08 by snpark            #+#    #+#             */
/*   Updated: 2021/01/07 12:01:22 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int		readnum;
	char		*buf;
	static char	*save;

	*line = ft_substr_free_s((char *)malloc(1), 0, 0);
	if (save && *save)
	{
		*line = ft_strjoin_free_s1(*line, save);
		(*line)[ft_strnewline(save)] = '\0';
		if (save[ft_strnewline(save)] == '\n')
		{
			save = ft_substr_free_s(save, ft_strnewline(save) + 1, ft_strlen(save));
			return (1);
		}
		free(save);
	}
	buf = (char *)malloc(BUFFER_SIZE);
	while ((readnum = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (ft_strnewline(buf) == BUFFER_SIZE)
		{
			*line = ft_strjoin_free_s1(*line, buf);
		}
		if (buf[ft_strnewline(buf)] == '\n')
		{
			*line = ft_strjoin_free_s1(*line, buf);
			(*line)[ft_strnewline(*line)] = '\0';
			save = ft_substr_free_s(buf, ft_strnewline(buf) + 1, BUFFER_SIZE);
			return (1);
		}
	}
	free(buf);
	if (readnum > 0)
		return (1);
	return (readnum > 0 ? 1 : readnum);
}
