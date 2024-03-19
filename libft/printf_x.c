/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:25:32 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/11 16:11:19 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 formats:
 dot:
 1) (0x/0X)(prc-000)(123)(width-blank) (left)
 2) (width-blank)(0x/0X)(prc-000)(123) (right)
 no dot:
 3) (width_blank)(0x/0X)(123) (right)
 4) (0x/0X)(width-zero)(123) (right)
*/

static void	cal_totalen(int len_hex, int *len_total,
			t_formats formats, unsigned int x)
{
	*len_total = len_hex;
	if (formats.precision > *len_total)
		*len_total = formats.precision;
	if (!(formats.sharp == 1 && x == 0))
		*len_total += 2 * formats.sharp;
}

static int	print_x1(t_formats *formats, int len_total)
{
	int	np;

	np = 0;
	if ((formats->minus == 0 && formats->dot == 1)
		|| (formats->minus == 0 && formats->dot == 0 && formats->zero == 0))
	{
		np += print_width(formats, len_total, ' ');
		if (formats->err < 0)
			return (formats->err);
	}
	return (np);
}

static int	print_x2(t_formats *formats, int len_hex, int len_total)
{
	int	np;

	np = 0;
	if (formats->minus == 0 && formats->dot == 0 && formats->zero == 1)
	{
		np += print_width(formats, len_total, '0');
		if (formats->err < 0)
			return (formats->err);
	}
	if (formats->dot == 1)
	{
		np += print_precision (formats, len_hex);
		if (formats->err < 0)
			return (formats->err);
	}
	return (np);
}

static int	print_x3(t_formats *formats, int len_total)
{
	int	np;

	np = 0;
	if (formats->minus == 1)
	{
		np += print_width(formats, len_total, ' ');
		if (formats->err < 0)
			return (formats->err);
	}
	return (np);
}

int	print_x(unsigned int x, t_formats *formats, char c)
{
	int	np;
	int	len_hex;
	int	len_total;

	np = 0;
	len_hex = len_uint(x, *formats, 16);
	cal_totalen(len_hex, &len_total, *formats, x);
	np += print_x1(formats, len_total);
	if (formats->err < 0)
		return (formats->err);
	np += print_0x(formats, c, x);
	if (formats->err < 0)
		return (formats->err);
	np += print_x2(formats, len_hex, len_total);
	if (formats->err < 0)
		return (formats->err);
	print_hex(x, c, formats, &np);
	if (formats->err < 0)
		return (formats->err);
	np += print_x3(formats, len_total);
	if (formats->err < 0)
		return (formats->err);
	return (np);
}
