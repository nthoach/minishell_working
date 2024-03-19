/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:34:44 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/12 16:38:35 by nthoach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1 != '\0')
		s1++;
	size = ft_strlen(s1);
	while (ft_strchr(set, s1[size]) && size != 0)
		size--;
	return (ft_substr(s1, 0, size + 1));
}

// static int	check_set(char c, char const *set)
// {
// 	while (*set)
// 	{
// 		if (c == *set)
// 			return (1);
// 		set++;
// 	}
// 	return (0);
// }
// static unsigned int	length_trim(char const *s1, char const *set)
// {
// 	unsigned int	len_tr;
// 	len_tr = 0;
// 	while (*s1)
// 	{
// 		if (!check_set(*s1, set))
// 			len_tr++;
// 		s1++;
// 	}
// 	return (len_tr);
// }
// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	unsigned int	len;
// 	char	*str_tr;
// 	char	*str;
// 	if (s1 == NULL || set == NULL)
// 		return (NULL);
// 	len = length_trim(s1, set);
// 	str_tr = (char *)malloc((len + 1) * sizeof(char));
// 	if (!str_tr)
// 		return (NULL);
// 	str = str_tr;
// 	while (*s1)
// 	{
// 		if (!check_set(*s1, set))
// 		{
// 			*str_tr = *s1;
// 			str_tr++;
// 		}		
// 		s1++;
// 	}
// 	*str_tr = '\0';
// 	return (str);
// }
// int	main()
// {
// 	const char *inputString = "  \tHello, World! \n";
// 	const char *trimSet = " \t\n"; // Set of characters to trim
// 	char *trimmedString = ft_strtrim(inputString, trimSet);
// 	if (trimmedString) {
// 	printf("Original String: \"%s\"\n", inputString);
// 	printf("Trimmed String: \"%s\"\n", trimmedString);
// 	free(trimmedString); // free the dynamically allocated memory
// 	} else {
// 	printf("Memory allocation failed.\n");
// 	}
// 	return (0);
// }