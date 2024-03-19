/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:23:58 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/11 16:11:19 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 two cases:
 1- right-justified
 2- left_justified
 parametesrs: "-" flag and the width, no precision
*/

void	print_hex(unsigned long n, char x, t_formats *formats, int *np)
{
	char	c;

	if (n == 0 && formats->dot == 1 && formats->precision == 0)
		return ;
	else
	{
		if (n >= 16)
		{
			print_hex(n / 16, x, formats, np);
			if (formats->err < 0)
				return ;
		}
		if (x == 'x' && (n % 16) > 9)
			c = (n % 16) - 10 + 'a';
		else if (x == 'X' && (n % 16) > 9)
			c = (n % 16) - 10 + 'A';
		else
			c = n % 16 + '0';
		*np += ft_putnchar(c, 1, &(formats->err));
		if (formats->err < 0)
			return ;
	}
}

int	print_p(unsigned long p, t_formats	*formats)
{
	int	np;
	int	len_p;

	np = 0;
	len_p = len_s_base((long long)p, 16);
	if (formats->minus == 0)
	{
		np += print_width(formats, len_p + 2, ' ');
		if (formats->err < 0)
			return (formats->err);
	}
	np += ft_putxstr("0x", 2, &(formats->err));
	if (formats->err < 0)
		return (formats->err);
	print_hex(p, 'x', formats, &np);
	if (formats->err < 0)
		return (formats->err);
	if (formats->minus == 1)
	{
		np += print_width(formats, len_p + 2, ' ');
		if (formats->err < 0)
			return (formats->err);
	}
	return (np);
}
