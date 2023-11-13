/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbinder < tbinder@student.42vienna.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:27:29 by tbinder           #+#    #+#             */
/*   Updated: 2023/11/13 13:37:26 by tbinder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <stdlib.h>

			//GET_NEXT_LINE
char		*get_next_line(int fd);
char		*ft_read_str(char *rest_str, int fd);
char		*ft_get_line(char *rest_str);
char		*ft_get_new_str(char *rest_str);

			//UTILS
char		*ft_strdub(char *rest_str);
char		*ft_strrchr(const char *rest_str, int a);
char		*ft_strjoin(char *rest_str, char *buf);
size_t		ft_strlen(char *str);
#endif
