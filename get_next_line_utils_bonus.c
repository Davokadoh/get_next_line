/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:23:47 by jleroux           #+#    #+#             */
/*   Updated: 2022/04/04 15:29:08 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((char) c == *s)
			return ((char *) s);
		s++;
	}
	if ((char) c == '\0')
		return ((char *) s);
	else
		return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	count;

	if (!dst || !src)
		return (0);
	i = 0;
	count = 0;
	while (src[count] != '\0')
		count++;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}	
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = 0;
	while (s1[len_s1] != '\0')
		len_s1++;
	len_s2 = 0;
	while (s2[len_s2] != '\0')
		len_s2++;
	new_str = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(&new_str[0], s1, len_s1 + 1);
	ft_strlcpy(&new_str[len_s1], s2, len_s2 + 1);
	return (new_str);
}

char	*ft_strdup(const char *s1)
{
	size_t	size;
	size_t	i;
	char	*new_str;

	if (!s1)
		return (NULL);
	size = 0;
	while (s1[size] != '\0')
		size++;
	new_str = malloc((size + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[size] = '\0';
	return (new_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sstr;
	size_t	strlen;

	if (s == NULL)
		return (NULL);
	strlen = 0;
	while (s[strlen] != '\0')
		strlen++;
	if (start > strlen)
		return (ft_strdup(""));
	if (strlen - start >= len)
		sstr = (char *)malloc((len + 1) * sizeof(char));
	else
		sstr = (char *)malloc((strlen - start + 1) * sizeof(char));
	if (sstr == NULL)
		return (NULL);
	ft_strlcpy(sstr, (s + start), (len + 1));
	return (sstr);
}
