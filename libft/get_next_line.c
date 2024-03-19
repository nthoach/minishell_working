/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:46:38 by nthoach           #+#    #+#             */
/*   Updated: 2024/01/11 16:26:01 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*add_text(char *store_in, char *buffer)
{
	char	*store_out;
	size_t	i;
	size_t	j;

	if (!store_in || !buffer)
		return (NULL);
	store_out = malloc((gnl_len(store_in) + gnl_len(buffer) + 1));
	if (!store_out)
		return (NULL);
	i = 0;
	j = 0;
	while (store_in[j] != '\0')
		store_out[i++] = store_in[j++];
	free(store_in);
	j = 0;
	while (buffer[j] != '\0')
		store_out[i++] = buffer[j++];
	store_out[i] = '\0';
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
	store_out = malloc(sizeof(char) * (gnl_len(store_in) - i + 1));
	if (!store_out)
		return (NULL);
	i++;
	while (store_in[i])
		store_out[j++] = store_in[i++];
	store_out[j] = '\0';
	free(store_in);
	return (store_out);
}

char	*read_line(char	*store_in, int fd)
{
	char	*buffer;
	int		n_byte;

	n_byte = 1;
	if (store_in == NULL)
		store_in = gnl_calloc(1, 1);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	while (n_byte > 0)
	{
		n_byte = read(fd, buffer, BUFFER_SIZE);
		if (n_byte == -1)
		{
			free(buffer);
			free(store_in);
			return (NULL);
		}
		buffer[n_byte] = 0;
		store_in = add_text(store_in, buffer);
		if (gnl_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (store_in);
}

char	*get_next_line(int fd)
{
	static char	*store_text;
	char		*line_out;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	store_text = read_line(store_text, fd);
	if (!store_text)
		return (NULL);
	line_out = extract_line(store_text);
	store_text = take_remain(store_text);
	return (line_out);
}
