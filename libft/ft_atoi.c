/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:45:34 by nthoach           #+#    #+#             */
/*   Updated: 2023/11/03 15:45:34 by nthoach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int			sign;	
	long long	value;
	long long	value_next;

	value = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		value_next = value * 10 + sign * (*str - '0');
		if (value_next > value && sign == -1)
			return (0);
		if (value_next < value && sign == 1)
			return (-1);
		value = value_next;
		str++;
	}
	return (value);
}

// int main()
// {
// 	char a[] = "	  +++--+-76543ffssf654";
//     printf("%d\n", ft_atoi(a));
//     printf("%d\n", atoi(a));
//      char b[] = "+++--+-76543ffssf654";
//     printf("%d\n", ft_atoi(b));
//     printf("%d\n", atoi(b));
//      char c[] = "     +76543ffssf654";
//     printf("%d\n", ft_atoi(c));
//     printf("%d\n", atoi(c));
//      char d[] = "2147483649";
//     printf("%d\n", ft_atoi(d));
//     printf("%d\n", atoi(d));
//          char e[] = "2147483649";
//     printf("%d\n", ft_atoi(e));
//     printf("%d\n", atoi(e));
// }