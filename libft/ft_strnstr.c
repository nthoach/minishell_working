/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:57:04 by honguyen          #+#    #+#             */
/*   Updated: 2023/10/30 15:25:00 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;

	b = 0;
	if ((big == NULL && little == NULL) || (big == NULL && len == 0))
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	while (big[b] && b < len)
	{
		l = 0;
		while (big[b + l] == little[l] && b + l < len)
		{
			l++;
			if (little[l] == '\0')
				return ((char *)&big[b]);
		}
		b++;
	}
	return (0);
}
