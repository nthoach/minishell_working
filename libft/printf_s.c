/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:42:47 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/11 16:11:19 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_s_left(t_formats *formats, char *s, int len, int n_blanks)
{
	int	np;

	np = 0;
	np += ft_putxstr(s, len, &(formats->err));
	if (formats->err < 0)
		return (-1);
	np += ft_putnchar(' ', n_blanks, &(formats->err));
	if (formats->err < 0)
		return (-1);
	return (np);
}

static int	print_s_right(t_formats *formats, char *s, int len, int n_blanks)
{
	int	np;

	np = 0;
	if (formats->zero == 1)
	{
		np += ft_putnchar('0', n_blanks, &(formats->err));
		if (formats->err < 0)
			return (-1);
	}
	else if (formats->zero == 0)
	{
		np += ft_putnchar(' ', n_blanks, &(formats->err));
		if (formats->err < 0)
			return (-1);
	}
	np += ft_putxstr(s, len, &(formats->err));
	if (formats->err < 0)
		return (-1);
	return (np);
}

static int	print_s_blanks(char *s, t_formats *formats)
{
	int	len;
	int	n_blanks;
	int	np;

	np = 0;
	len = (int) ft_strlen(s);
	if (formats->dot == 1 && formats->precision < len)
		len = formats->precision;
	n_blanks = formats->width - len;
	if (formats->minus == 1)
	{
		np += print_s_left(formats, s, len, n_blanks);
		if (formats->err < 0)
			return (formats->err);
	}
	else
	{
		np += print_s_right(formats, s, len, n_blanks);
		if (formats->err < 0)
			return (formats->err);
	}
	return (np);
}

/* print_s:
	Cases:
	1) %.s <-> %.0s precsion = 1
		-> print: "" (empty string), precion 			
	2) width < len(s)-> whole string print
	3) width > len(s) -> (width - precsion/len) of blanks
	4) %0 -> underfined because of string, not a number
	5) %- -> ignore 0 (left-justified): %-5.1, "Hi" [Hi   ]
	6) s = NULL -> print "(null)"
	7) empty string (*s = '\0') -> print ""
	8) '\0' in the string, printing s is stopped.
*/
int	print_s(char *s, t_formats *formats)
{
	int	np;
	int	flag;

	flag = 0;
	np = 0;
	if (!s)
	{
		s = ft_strdup("(null)");
		if (!s)
		{
			formats->err = -1;
			return (formats->err);
		}
		flag = 1;
	}
	np += print_s_blanks(s, formats);
	if (flag == 1)
		free(s);
	if (formats->err < 0)
		return (formats->err);
	return (np);
}
