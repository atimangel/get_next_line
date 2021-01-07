/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 14:13:50 by snpark            #+#    #+#             */
/*   Updated: 2021/01/07 15:13:27 by senoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strjoin_free_s1(char *s1, char const *s2);
char	*ft_substr_free_s(char *s, unsigned int start, size_t len);
size_t	ft_strnewline(char *s);
int	get_next_line(int fd, char **line);
#endif
