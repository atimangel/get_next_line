/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 07:28:35 by snpark            #+#    #+#             */
/*   Updated: 2021/01/12 07:32:15 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	sub_get(char **dest, char *src, char **save)
{
	char *tmp;

	tmp = *dest;
	*dest = ft_strjoin(*dest, src);
	free(tmp);
	if (src[ft_strnewline(src)] == '\n')
	{
		tmp = *dest;
		*dest = ft_substr(*dest, 0, ft_strnewline(*dest));
		free(tmp);
		if (src[ft_strnewline(src) + 1] != '\0')
			*save = ft_substr(src, ft_strnewline(src) + 1,
					ft_strlen(src) - ft_strnewline(src) - 1);
		return (1);
	}
	return (0);
}

static void	ft_free_save(char *tmp, char **save)
{
	free(tmp);
	if (*save == tmp)
		*save = 0;
}

int			get_next_line(int fd, char **line)
{
	int			readnum;
	char		buf[BUFFER_SIZE + 1];
	static char	*save[258];
	char		*tmp;
	int			return_subget;

	if ((fd < 0 && fd > 259) || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	*line = ft_substr("", 0, 0);
	if (save[fd])
	{
		tmp = save[fd];
		return_subget = sub_get(line, tmp, &save[fd]);
		ft_free_save(tmp, &save[fd]);
		if (return_subget == 1)
			return (1);
	}
	while ((readnum = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[readnum] = '\0';
		return_subget = sub_get(line, buf, &save[fd]);
		if (return_subget == 1)
			return (1);
	}
	return (readnum > 0 ? 1 : readnum);
}
