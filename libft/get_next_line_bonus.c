/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:46:38 by nthoach           #+#    #+#             */
/*   Updated: 2024/01/11 16:24:53 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*add_text(char *store_in, char *buffer)
{
	char	*store_out;
	size_t	i;
	size_t	j;

	store_out = malloc(gnl_len(store_in) + gnl_len(buffer) + 1);
	if (!store_out)
		return (NULL);
	i = 0;
	j = 0;
	while (store_in[j])
		store_out[i++] = store_in[j++];
	j = 0;
	while (buffer[j])
		store_out[i++] = buffer[j++];
	store_out[i] = 0;
	free(store_in);
	return (store_out);
}

char	*extract_line(char *store_text)
{
	char	*line_out;
	size_t	len;
	size_t	i;

	len = 0;
	if (!store_text[0])
		return (NULL);
	while (store_text[len] && store_text[len] != '\n')
		len++;
	line_out = malloc((len + 2) * sizeof(char));
	if (!line_out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line_out[i] = store_text[i];
		i++;
	}
	if (store_text[len] == '\n')
		line_out[len++] = '\n';
	line_out[len] = '\0';
	return (line_out);
}

char	*take_remain(char	*store_in)
{
	char	*store_out;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (store_in[i] && store_in[i] != '\n')
		i++;
	if (!store_in[i])
	{
		free(store_in);
		return (NULL);
	}
	store_out = malloc(gnl_len(store_in) - i + 1);
	if (!store_out)
		return (NULL);
	i++;
	while (store_in[i])
		store_out[j++] = store_in[i++];
	store_out[j] = '\0';
	free(store_in);
	return (store_out);
}

char	*read_line(char	*store_text, int fd)
{
	char	*buffer;
	int		by_r;

	by_r = 1;
	if (store_text == NULL)
		store_text = gnl_calloc(1, 1);
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	while (by_r > 0)
	{
		by_r = read(fd, buffer, BUFFER_SIZE);
		if (by_r == -1)
		{
			free(buffer);
			free(store_text);
			return (NULL);
		}
		buffer[by_r] = 0;
		store_text = add_text(store_text, buffer);
		if (gnl_strchr(buffer, '\n') == 1)
			break ;
	}
	free(buffer);
	return (store_text);
}

char	*get_next_line(int fd)
{
	static char	*store_text[FOPEN_MAX];
	char		*line_out;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	store_text[fd] = read_line(store_text[fd], fd);
	if (!store_text[fd])
		return (NULL);
	line_out = extract_line(store_text[fd]);
	store_text[fd] = take_remain(store_text[fd]);
	return (line_out);
}
