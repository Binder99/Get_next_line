/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbinder < tbinder@student.42vienna.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:27:22 by tbinder           #+#    #+#             */
/*   Updated: 2023/11/11 13:09:04 by tbinder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *rest_str, char *buf)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!rest_str)
	{
		rest_str = (char *)malloc(1 * sizeof(char));
		rest_str[0] = '\0';
	}
	if (!rest_str || !buf)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(rest_str) + ft_strlen(buf) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (rest_str[++i] != '\0')
		str[i] = rest_str[i];
	while (buf[j] != '\0')
		str[i++] = buf[j++];
	str[i] = '\0';
	free(rest_str);
	return (str);
}

char	*ft_strrchr(const char *rest_str, int a)
{
	char	*str;
	char	find;

	str = (char *) rest_str;
	find = (char) a;
	while (*str)
	{
		if (*str == find)
			return (str);
		str++;
	}
	if (*str != find)
		return (NULL);
	return (str);
}

char	*ft_strdub(char *rest_str)
{
	size_t		len;
	size_t		i;
	char		*new_str;

	len = 0;
	while (rest_str[len] != '\0')
		len++;
	new_str = (char *)malloc(len + 1);
	if (new_str != NULL)
	{
		i = 0;
		while (i < len)
		{
			new_str[i] = rest_str[i];
			i++;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}
