/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:31:50 by honguyen          #+#    #+#             */
/*   Updated: 2023/10/30 14:46:53 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)(*s) == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (!(char)c)
		return ((char *)s);
	return (NULL);
}

// char	*ft_strchr(const char *str, int c)
// {
// 	if (!(char)c)
// 		return (NULL);
// 	while (*str)
// 	{
// 		if (*str == (char)c)
// 			return ((char *)str);
// 		str++;
// 	}
// 	return (NULL);
// }
