/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_err.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:46:38 by nthoach           #+#    #+#             */
/*   Updated: 2024/02/20 05:55:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line_err(int fd, int err)
{
	static char	*store_text;
	char		*line_out;

	if (err)
	{
		if (store_text)
			free(store_text);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	store_text = read_line(store_text, fd);
	if (!store_text)
		return (NULL);
	line_out = extract_line(store_text);
	store_text = take_remain(store_text);
	return (line_out);
}
