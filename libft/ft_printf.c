/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:29:54 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/11 16:07:48 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	printing the data types after %, need to move va_arg
	order:
	1- Reset the formats variable to zeros
	2- write the format flags to formats, 
	*s updated inside each subfunction
	3- write the width number to formats
	4- if having "." -> get precision
	5- recognize data type flags and print the relevant data types
*/
static int	print_options(va_list ap, char **s, int *err)
{
	int			np;
	t_formats	formats;

	np = 0;
	ft_memset(&formats, 0, sizeof(t_formats));
	get_flags(&formats, s);
	get_width_prcn(&formats.width, s);
	if (**s == '.')
	{
		formats.dot = 1;
		(*s)++;
		get_width_prcn(&(formats.precision), s);
	}
	if (ft_strchr("cspdiuxX%", **s) != 0)
		np = print_types(ap, &formats, s);
	*err = formats.err;
	return (np);
}

/* 
	two cases:
	1-Normal string --> rpint
	2- 
*/
static int	printf_loop(va_list ap, char **s, int *err)
{
	int	np;

	np = 0;
	if (**s == '%')
	{
		(*s)++;
		np += print_options(ap, s, err);
		if (*err < 0)
			return (*err);
	}
	else
	{
		np += ft_putnchar(**s, 1, err);
		if (*err < 0)
			return (*err);
	}
	(*s)++;
	if (*err < 0)
		return (*err);
	return (np);
}

int	ft_printf(const	char *s_in, ...)
{
	char	*s;
	int		np;
	va_list	ap;
	int		error;

	error = 0;
	np = 0;
	s = (char *) s_in;
	va_start(ap, s_in);
	while (*s)
	{
		np += printf_loop(ap, &s, &error);
		if (error < 0)
			return (error);
	}
	va_end(ap);
	return (np);
}
