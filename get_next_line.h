/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:40:17 by souhsain          #+#    #+#             */
/*   Updated: 2025/11/04 21:19:24 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#define BUFFER_SIZE 5

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
