/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axicola- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:11:00 by axicola-          #+#    #+#             */
/*   Updated: 2025/09/02 15:24:34 by axicola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		total_len;
	char		*result;
	int			i;
	int			j;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc((total_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		result[i++] = s2[j++];
	}
	result[i] = '\0';
	free(s1);
	return (result);
}

char	*sanitase(char *stash)
{
	char	*newline_pos;
	char	*nuevo_stash;
	int		len;

	newline_pos = ft_strchr(stash, '\n');
	if (newline_pos)
		len = newline_pos - stash + 1;
	else
		len = ft_strlen(stash);
	nuevo_stash = ft_substr(stash, 0, len);
	return (nuevo_stash);
}

char	*sanitazeinverso(char *stash)
{
	char	*newline_pos;
	char	*resto;

	newline_pos = ft_strchr(stash, '\n');
	if (!newline_pos)
		return (NULL);
	resto = ft_strdup(newline_pos + 1);
	return (resto);
}

static char	*read_and_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bites_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
	{
		bites_read = read(fd, buffer, BUFFER_SIZE);
		if (bites_read <= 0)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[bites_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*linea;
	char		*old_stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	stash = read_and_stash(fd, stash);
	if (!stash || !*stash)
		return (NULL);
	linea = sanitase(stash);
	old_stash = stash;
	stash = sanitazeinverso(stash);
	if (stash == NULL)
		free(old_stash);
	else
		free(old_stash);
	return (linea);
}
