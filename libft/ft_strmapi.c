/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:34:40 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/09 18:03:56 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (*s)
	{
		str[i] = f(i, *s);
		i++;
		s++;
	}
	str[i] = '\0';
	return (str);
}

//
// char custom_map(unsigned int index, char c)
// {
// 	if ( c >= 'a' && c <= 'z')
// 		return (c - 32);
// 	return (c);
// }

// int	main()
// {
// 	const char *inputString = "Hello, World";
// 	char	*result = ft_strmapi(inputString, custom_map);

// 	if (result)
// 	{
// 		printf("Original String: %s\n", inputString);
// 		printf("Mapped String: %s\n", result);
// 		free(result);
// 	}
// 	else
// 		printf("Memory allocation failed.\n");
// 	return (0);
// }