/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:40:17 by souhsain          #+#    #+#             */
/*   Updated: 2025/11/09 12:33:24 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef INT_MAX
#define INT_MAX 2147483647
#endif

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

#if BUFFER_SIZE > INT_MAX
#undef BUFFER_SIZE
#define BUFFER_SIZE -1
#endif

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

#endif
