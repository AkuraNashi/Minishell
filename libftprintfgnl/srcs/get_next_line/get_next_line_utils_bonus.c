/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <lcamilo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:28:43 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/10/27 00:28:43 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strlenjoin(const char *s1, const char *s2, int len)
{
	char	*str;
	char	*ret;

	if (!(s1 && s2))
		return (0);
	str = malloc((ft_strlen(s1) + len + 1) * sizeof(char));
	ret = str;
	if (!str)
		return (0);
	while (*s1)
		*(str++) = *(s1++);
	while (len > 0)
	{
		*(str++) = *(s2++);
		len--;
	}
	*str = 0;
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == ((char)c))
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strlen(src));
}

char	*ft_strlendup(const char *s1, int size)
{
	char	*p;

	p = malloc((size + 1) * sizeof(char));
	if (!p)
		return (0);
	ft_strlcpy(p, s1, size + 1);
	return (p);
}
