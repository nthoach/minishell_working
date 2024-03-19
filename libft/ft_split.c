/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:07:15 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/04 12:42:06 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_array(const char *str, char c)
{
	int		sz_ar;
	char	str_1;

	str_1 = c;
	sz_ar = 0;
	while (*str)
	{
		if (str_1 == c && *str != c)
			sz_ar++;
		str_1 = *str;
		str++;
	}
	return (sz_ar);
}

static int	size_str(const char *str, int *k, char c)
{
	int	size;
	int	count;

	count = 0;
	size = 0;
	while (*str == c && *str)
	{
		str++;
		count++;
	}
	*k = count;
	while (*str != c && *str)
	{
		size++;
		str++;
	}
	return (size);
}

static void	free_loc(char **ptr, int i)
{
	while (i >= 0)
	{
		free(ptr[i]);
		i--;
	}
	free(ptr);
}

static char	**array_copy(char **ptr, char const *s, int ar_sz, char c)
{
	int	i;
	int	k;
	int	str_sz;

	i = 0;
	k = 0;
	while (i < ar_sz && *s)
	{
		str_sz = size_str(s, &k, c);
		s += k;
		ptr[i] = ft_substr(s, 0, str_sz);
		if (!(ptr[i]))
		{
			free_loc(ptr, i - 1);
			return (NULL);
		}
		s += str_sz;
		i++;
	}
	ptr[ar_sz] = 0;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		ar_sz;
	char	**ptr;

	ar_sz = size_array(s, c);
	ptr = (char **) malloc((ar_sz + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	ptr = array_copy(ptr, s, ar_sz, c);
	return (ptr);
}

// static int	size_str(const char *str, int *k, char c)
// {
// 	int	size;
// 	int	count;

// 	count = 0;
// 	size = 0;
// 	while (*str == c && *str)
// 	{
// 		str++;
// 		count++;
// 	}
// 	*k = count;
// 	while (*str != c && *str)
// 	{
// 		size++;
// 		str++;
// 	}
// 	return (size);
// }

// static void	ft_strncpy(char *dest, const char *src, int sz_st)
// {
// 	dest += sz_st;
// 	*dest = '\0';
// 	dest--;
// 	src += sz_st - 1;
// 	while (sz_st)
// 	{
// 		*dest-- = *src--;
// 		sz_st--;
// 	}
// }

// char	**ft_split(char const *s, char c)
// {
// 	int		i;
// 	int		k;
// 	int		ar_sz;
// 	int		str_sz;
// 	char	**ptr;

// 	ar_sz = size_array(s, c);
// 	ptr = (char **) malloc((ar_sz + 1) * sizeof(char *));
// 	if (ptr == NULL)
// 		return (NULL);
// 	i = 0;
// 	k = 0;
// 	while (i < ar_sz && *s)
// 	{
// 		str_sz = size_str(s, &k, c);
// 		ptr[i] = (char *) malloc((str_sz + 1) * sizeof(char));
// 		if (!(ptr[i]))
// 			return (NULL);
// 		s = s + k;
// 		ft_strncpy(ptr[i], s, str_sz);
// 		s = s + str_sz;
// 		i++;
// 	}
// 	ptr[ar_sz] = 0;
// 	return (ptr);
// }

// int main() 
// {
//     const char *inputString = "This Mac Mini features a 5nm Apple"
//     "M2 Pro 64-bit SoC processor with 10 cores (4 performance cores,"
//     " 4 efficiency cores) clocked at 3.49 GHz.";
//     char **tokens = ft_split(inputString, ' ');
//     for (int i = 0; tokens[i] != NULL; i++) {
//         printf("Token %d: %s\n", i, tokens[i]);
//         free(tokens[i]); // Free individual tokens
//     }
//     free(tokens); // Free the array of tokens
//     return 0;
// }
