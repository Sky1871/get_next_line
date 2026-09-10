/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 21:54:35 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/10 17:40:11 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

void	read_to_buf(int fd, char **buf)
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return ;
	while (find_line(*buf))
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i == -1)
		{
			free(temp);
			free(*buf);
			*buf = NULL;
			return ;
		}
		else if (i == 0)
			break ;
		temp[i] = '\0';
		*buf = ft_strjoin(*buf, temp);
	}
	free(temp);
	return ;
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*ret;

	if (!buf)
	{
		buf = malloc(1);
		if (!buf)
			return (NULL);
		buf[0] = '\0';
	}
	read_to_buf(fd, &buf);
	if (!buf)
		return (NULL);
	if (buf[0] == '\0')
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	ret = return_line(buf);
	buf = delete_line(buf, ft_strlen(ret));
	return (ret);
}
