/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:22:40 by jleroux           #+#    #+#             */
/*   Updated: 2022/04/04 15:28:46 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);

char	*ft_strchr(const char *s, int c);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strdup(const char *s1);

char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
