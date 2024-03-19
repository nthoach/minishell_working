/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printfdi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:29:36 by honguyen          #+#    #+#             */
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

int	print_di1(t_formats *formats, int n)
{
	int	np;

	np = 0;
	np += print_width(formats, formats->len_total, ' ');
	if (formats->err < 0)
		return (formats->err);
	np += print_sign(formats, n);
	if (formats->err < 0)
		return (formats->err);
	np += print_precision(formats, formats->len_digit);
	if (formats->err < 0)
		return (formats->err);
	if (!(n == 0 && formats->dot == 1 && formats->precision == 0))
	{
		ft_putnbr((long)n, &np, &(formats->err));
		if (formats->err < 0)
			return (formats->err);
	}
	return (np);
}

int	print_di2(t_formats *formats, int n)
{
	int	np;

	np = 0;
	np += print_sign(formats, n);
	if (formats->err < 0)
		return (formats->err);
	np += print_width(formats, formats->len_total, '0');
	if (formats->err < 0)
		return (formats->err);
	ft_putnbr(n, &np, &(formats->err));
	if (formats->err < 0)
		return (formats->err);
	return (np);
}

int	print_di3(t_formats *formats, int n)
{
	int	np;

	np = 0;
	np += print_width(formats, formats->len_total, ' ');
	if (formats->err < 0)
		return (formats->err);
	np += print_sign(formats, n);
	if (formats->err < 0)
		return (formats->err);
	ft_putnbr(n, &np, &(formats->err));
	if (formats->err < 0)
		return (formats->err);
	return (np);
}

int	print_di4(t_formats *formats, int n)
{
	int	np;

	np = 0;
	np += print_sign(formats, n);
	if (formats->err < 0)
		return (formats->err);
	np += print_precision(formats, formats->len_digit);
	if (formats->err < 0)
		return (formats->err);
	if (!(n == 0 && formats->dot == 1 && formats->precision == 0))
	{
		ft_putnbr(n, &np, &(formats->err));
		if (formats->err < 0)
			return (formats->err);
	}
	np += print_width(formats, formats->len_total, ' ');
	if (formats->err < 0)
		return (formats->err);
	return (np);
}
