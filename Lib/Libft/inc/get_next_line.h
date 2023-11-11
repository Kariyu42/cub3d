/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:19:35 by kquetat-          #+#    #+#             */
/*   Updated: 2023/11/10 13:44:16 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <strings.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *str, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);

#endif
