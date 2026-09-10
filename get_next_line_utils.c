/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 21:54:35 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/10 03:39:54 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *buf, char *str)
{
	int		i;
	int		n;
	char	*ret;

	i = ft_strlen(buf);
	n = ft_strlen(str);
	ret = malloc(sizeof(char) * (i + n + 1));
	if (!ret)
	{
		free(str);
		free(buf);
		return (NULL);
	}
	i = -1;
	n = -1;
	while (buf[++i])
		ret[i] = buf[i];
	while (str[++n])
		ret[i++] = str[n];
	ret[i] = '\0';
	free(buf);
	free(str);
	return (ret);
}

char	*delete_line(char *buf, int len)
{
	int		i;
	char	*ret;

	if (!buf)
		return (NULL);
	i = ft_strlen(buf);
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
