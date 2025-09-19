/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axicola- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:40:49 by axicola-          #+#    #+#             */
/*   Updated: 2025/09/18 19:41:02 by axicola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

void			*ft_memcpy(void *dst, const void *src, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_substr(const char *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
char			*ft_strjoin(char *s1, char *s2);
char			*sanitase(char *stash);
char			*sanitazeinverso(char *stash);
char			*get_next_line(int fd);

#endif
