/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:22:56 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/11 16:11:19 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	(1) printing signed integer numbers with %d and %i
	[%#d] [%#i] has no effective of # because there is no
	alternative ways to present d or i
	(2) range is singed integer typeof(int)
	(3) Blanks and justify flags printed if width > len(itoa(d_i))
	(4) width < len: no justify, print the whole length
	(5) if .prcn, with precision > len, [000ddd] printed
	(6) [+000dd] [-00dd] [ 00dd], [ ] is only when no -(left justified), 
	and for positive number only
	(7) precision < len -> ignore precison, print whole len
	(8) prescision = 0 && di = 0, no print
	(9) if having "w.p" (having precision), ignore flag "0"
	(10) "+"" will disable " ", and "-" will disable "0"
	exmaples:
	left_justified with "-":
	[(+/-/ )(prc-000)(123)(   )] with "-" left-justified
	right_justified and .precision
	[(  )((+/-/ )(prc-000)(123))] right-justified if width > len
	[(+/-/ )(123)] right-justified if width < len
	right_justified && no .precision and width > len
	no "0": (  )(+- )(123)
	yes "0": (+- )(000-width)(123)
*/

static int	print_di23(int n, t_formats *formats)
{
	int	np;

	np = 0;
	if (formats->zero == 1)
	{
		np += print_di2(formats, n);
		if (formats->err < 0)
			return (formats->err);
	}
	else
	{
		np += print_di3(formats, n);
		if (formats->err < 0)
			return (formats->err);
	}
	return (np);
}

int	print_di(int n, t_formats *formats)
{
	int	np;

	np = 0;
	formats->len_digit = len_int(n);
	formats->len_total = totalize_len(n, formats->len_digit, formats);
	if (formats->precision == 0 && formats->dot == 1 && n == 0)
		(formats->len_total)--;
	if (formats->minus == 0 && formats->dot == 1)
	{
		np += print_di1(formats, n);
		if (formats->err < 0)
			return (formats->err);
	}
	if (formats->minus == 0 && formats->dot == 0)
		np += print_di23(n, formats);
	if (formats->err < 0)
		return (formats->err);
	if (formats->minus == 1)
	{
		np += print_di4(formats, n);
		if (formats->err < 0)
			return (formats->err);
	}
	return (np);
}
