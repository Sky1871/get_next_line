/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 21:54:35 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/10 07:53:15 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*read_to_buf(int fd, char *buf)
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	while (find_line(buf))
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i == -1)
		{
			free(temp);
			free(buf);
			return (NULL);
		}
		else if (i == 0)
			break ;
		temp[i] = '\0';
		buf = ft_strjoin(buf, temp);
	}
	free(temp);
	return (buf);
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
	buf = read_to_buf(fd, buf);
	if (!buf)
		return (NULL);
	if (buf[0] == '\0')
	{
		free(buf);
		return (NULL);
	}
	ret = return_line(buf);
	buf = delete_line(buf, ft_strlen(ret));
	return (ret);
}
