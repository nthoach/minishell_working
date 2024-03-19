/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:07:54 by honguyen          #+#    #+#             */
/*   Updated: 2023/05/21 16:19:41 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((n > 0) && (*s1 || *s2))
	{
		if ((unsigned char)(*s1) != (unsigned char)(*s2))
			return ((unsigned char)(*s1) - (unsigned char)(*s2));
		s1++;
		s2++;
		n--;
	}
	return (0);
}

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	while (n > 0 && *s1 && *s2)
// 	{
// 		if ((*s1 > *s2) || (*s1 < *s2))
// 			return (*s1 - *s2);
// 		else
// 		{
// 			s1++;
// 			s2++;
// 			n--;
// 		}
// 	}
// 	return (0);
// }
