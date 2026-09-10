/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 21:54:35 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/10 02:35:41 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*delete_line(char *buf, int len)
{
	int		i;
	char	*ret;

	i = 0;
	if (!buf)
		return (NULL);
	while (buf[i])
		i++;
	if (len >= i)
	{
		free(buf);
		return (NULL);
	}
	ret = malloc(sizeof(char) * (i - len + 1));
	if (!ret)
	{
		free(buf);
		return (NULL);
	}
	i = 0;
	while (buf[len])
		ret[i++] = buf[len++];
	ret[i] = '\0';
	free(buf);
	return (ret);
}

char	*find_line(char *buf)
{
	int		i;
	int		n;
	char	*ret;

	i = 0;
	n = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	if (buf[i] == '\n')
		i++;
	ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	while (n != i)
	{
		ret[n] = buf[n];
		n++;
	}
	ret[n] = '\0';
	return (ret);
}
