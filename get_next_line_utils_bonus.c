/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:32:11 by souhsain          #+#    #+#             */
/*   Updated: 2025/11/07 12:01:33 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
size_t	ft_strlen(const char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	srclen;
	size_t	count;

	srclen = ft_strlen(src);
	count = 0;
	if (destsize == 0)
		return (srclen);
	while (count < destsize - 1 && src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (srclen);
}
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destlen;
	size_t	srclen;
	size_t	count;

	srclen = ft_strlen(src);
	if (!dest && size == 0)
		return (srclen);
	count = 0;
	destlen = ft_strlen(dest);
	if (size <= destlen)
		return (size + srclen);
	while (count + destlen < size -1 && src[count] != '\0')
	{
		dest[destlen + count] = src[count];
		count++;
	}
	dest[destlen + count] = '\0';
	return (destlen + srclen);
}
char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*pdest;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	pdest = malloc(s1len + s2len + 1);
	if (!pdest)
		return (NULL);
	ft_strlcpy(pdest, s1, s1len + 1);
	ft_strlcat(pdest, s2, s1len + s2len + 1);
	return (pdest);
}