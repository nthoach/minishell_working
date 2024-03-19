/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:30:44 by marvin            #+#    #+#             */
/*   Updated: 2023/10/31 17:30:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str_d;
	int		size;
	int		i;

	size = ft_strlen((char *)s);
	str_d = (char *)malloc((size + 1) * sizeof(char));
	if (!str_d)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str_d[i] = (char)s[i];
		i++;
	}
	str_d[i] = '\0';
	return (str_d);
}
