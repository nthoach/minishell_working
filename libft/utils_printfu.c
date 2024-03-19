/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printfu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:06:58 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/11 16:11:19 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	3 cases:
	(1) (prc-zero)(1234)(width-blank) for "%-. "
	(2) (width-blank)(prc-zero)(1234) for ".0" no "-"
	(3) (width-blank)(1234) for " no 0" "no ." no "-"
	(4) (wdt-zero)(1234) for "0" no "-" no "."
*/

int	len_uint(unsigned int n, t_formats formats, int base)
{
	int	len;

	if (n == 0 && formats.dot == 1 && formats.precision == 0)
		return (0);
	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

int	total_len(int precision, int len_u)
{
	int	len_total;

	len_total = len_u;
	if (precision > len_total)
		len_total = precision;
	return (len_total);
}

void	ft_putpnbr(unsigned int n, t_formats *formats, int *np)
{
	char	c;

	if (n == 0 && formats->dot == 1 && formats->precision == 0)
		return ;
	else
	{
		if (n >= 10)
		{
			ft_putpnbr(n / 10, formats, np);
			if (formats->err < 0)
				return ;
		}
		c = n % 10 + '0';
		*np += ft_putnchar(c, 1, &(formats->err));
		if (formats->err < 0)
			return ;
	}
}
