/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:16:54 by nthoach           #+#    #+#             */
/*   Updated: 2023/11/03 18:16:54 by nthoach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *by, int c, size_t size)
{
	unsigned char	*p;

	p = (unsigned char *) by;
	while (size--)
		*p++ = (unsigned char) c;
	return (by);
}
