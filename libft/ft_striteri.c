/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:42:07 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/04 13:42:07 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// int	print_sample(int	index, char	*c)
// {
// 	printf("Character at index %d: %c\n", index, *c);
// 	return (0);
// }

// int	main()
// {
// 	char testString[] = "0123456 ";

// 	printf("Original String: %s\n", testString);
//    	printf("Applying the function:\n");
// 	// Test the ft_striter function with the sample function
// 	ft_striteri(testString, print_sample);
//     return 0;
// }