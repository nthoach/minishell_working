/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:34:37 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/07 22:54:48 by nthoach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*j_s;
	char	*ptr;
	size_t	len_t;

	if (!s1 || !s2)
		return (NULL);
	len_t = ft_strlen(s1) + ft_strlen(s2);
	j_s = (char *)malloc((len_t + 1) * sizeof(char));
	if (!j_s)
		return (NULL);
	ptr = j_s;
	while (*s1)
		*j_s++ = *s1++;
	while (*s2)
		*j_s++ = *s2++;
	*j_s = '\0';
	return (ptr);
}

// int	main()
// {
//     char *s1 = "Hello, ";
//     char *s2 = "World!";
//     char *result = ft_strjoin(s1, s2);

//     if (result) 
// {
//         printf("Concatenated String: %s\n", result);
// }
// else {
//         printf("Memory allocation failed.\n");
//      }
// free(result); // Don't forget to free the dynamically allocated memory
//     return 0;
// }