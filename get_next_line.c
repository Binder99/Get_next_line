/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbinder < tbinder@student.42vienna.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:27:17 by tbinder           #+#    #+#             */
/*   Updated: 2023/11/13 13:57:51 by tbinder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_new_str(char *rest_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (rest_str[i] && rest_str[i] != '\n')
		i++;
	if (!rest_str[i])
		return (free(rest_str), (NULL));
	str = (char *)malloc(sizeof(char) * (ft_strlen(rest_str) - i + 1));
	if (!str)
		return (free(rest_str), (NULL));
	i++;
	j = 0;
	while (rest_str[i])
		str[j++] = rest_str[i++];
	str[j] = '\0';
	return (free(rest_str), (str));
}

char	*ft_get_line(char *rest_str)
{
	char	*line;
	int		i;

	if (!rest_str || !*rest_str)
		return (NULL);
	i = 0;
	while (rest_str[i] && rest_str[i] != '\n')
		i++;
	if (rest_str[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (free(line), (NULL));
	i = 0;
	while (rest_str[i] && rest_str[i] != '\n')
	{
		line[i] = rest_str[i];
		i++;
	}
	if (rest_str[i] == '\n')
	{
		line[i] = rest_str[i];
		i++;
	}
	return ((line[i] = '\0'), (line));
}

char	*ft_read_str(char *rest_str, int fd)
{
	char	*buffer;
	int		rd_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(rest_str), (NULL));
	rd_bytes = 1;
	while (!ft_strrchr(rest_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes == -1)
			return (free(rest_str), free(buffer), (NULL));
		buffer[rd_bytes] = '\0';
		rest_str = ft_strjoin(rest_str, buffer);
		if (!rest_str)
			return (free(buffer), (NULL));
	}
	return (free(buffer), (rest_str));
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!rest_str)
	{
		rest_str = ft_strdub("");
		if (!rest_str)
			return (NULL);
	}
	rest_str = ft_read_str(rest_str, fd);
	if (!rest_str)
		return (free(rest_str), (NULL));
	line = ft_get_line(rest_str);
	rest_str = ft_get_new_str(rest_str);
	return (line);
}
