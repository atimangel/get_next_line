/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 13:19:23 by snpark            #+#    #+#             */
/*   Updated: 2021/01/07 11:57:45 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

/*
int		get_next_line(int fd, char **line)
{
	int	readnum;
	char	*buf;
	static char *save;

	*line = ft_substr_free_s((char *)malloc(1), 0, 0);
	if (save && *save)
	{
		*line = ft_strjoin_free_s1(*line, save);
		(*line)[ft_strnewline(save)] = '\0';
		if (save[ft_strnewline(save)] == '\n')
		{
			save = ft_substr_free_s(save, ft_strnewline(save) + 1, ft_strlen(save));
	//		printf("old save = %s\n", save);
			return (1);
		}
	//	printf("free save\n");
		free(save);
	}
	buf = (char *)malloc(BUFFER_SIZE);
	while ((readnum = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (ft_strnewline(buf) == BUFFER_SIZE)
		{
		//	printf("same\n");
			*line = ft_strjoin_free_s1(*line, buf);
		}
		if (buf[ft_strnewline(buf)] == '\n')
		{
			*line = ft_strjoin_free_s1(*line, buf);
			(*line)[ft_strnewline(*line)] = '\0';
			save = ft_substr_free_s(buf, ft_strnewline(buf) + 1, BUFFER_SIZE);
		//	printf("save = %s\n", save);
			return (1);
		}
	}
	free(buf);
	if (readnum > 0)
		return (1);
}*/

int		main(void)
{
	ssize_t fd;
	char	*line;

	line = 0;
	fd = open("text.txt", O_RDONLY);
	while ((get_next_line(fd, &line) == 1))
	{
		if (*line)
			printf("line string = %s\n", line);
			free(line);
	}
	return (0);
}
