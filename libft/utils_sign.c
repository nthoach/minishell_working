/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:54:04 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/11 16:11:19 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_s_base(unsigned long n, int base)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

int	len_int(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	totalize_len(int n, int no_digit, t_formats *p)
{
	int	len_total;

	len_total = no_digit;
	if (n < 0 || (n >= 0 && (*p).plus == 1)
		|| (n >= 0 && (*p).space == 1))
		(*p).sign = 1;
	if ((*p).precision > no_digit)
		len_total = (*p).precision;
	len_total += (*p).sign;
	return (len_total);
}

int	print_sign(t_formats *formats, int n)
{
	int	np;

	np = 0;
	if (n >= 0 && formats->plus == 1)
	{
		np += ft_putnchar('+', 1, &(formats->err));
		if (formats->err < 0)
			return (formats->err);
		return (np);
	}
	else if (n >= 0 && formats->space == 1)
	{
		np += ft_putnchar(' ', 1, &(formats->err));
		if (formats->err < 0)
			return (formats->err);
	}
	else if (n < 0)
	{
		np += ft_putnchar('-', 1, &(formats->err));
		if (formats->err < 0)
			return (formats->err);
	}
	return (np);
}

int	print_0x(t_formats *formats, char c, unsigned int x)
{
	int	count;

	count = 0;
	if (c == 'x' && formats->sharp == 1 && x != 0)
	{
		count += ft_putxstr("0x", 2, &(formats->err));
		if (formats->err < 0)
			return (formats->err);
	}
	if (c == 'X' && formats->sharp == 1 && x != 0)
	{
		count += ft_putxstr("0X", 2, &(formats->err));
		if (formats->err < 0)
			return (formats->err);
	}
	return (count);
}
