/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:31:52 by souhsain          #+#    #+#             */
/*   Updated: 2025/11/08 23:14:08 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

#ifndef INT_MAX
#define INT_MAX 2147483647
#endif

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

char	*get_next_line_bonus(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

#endif
