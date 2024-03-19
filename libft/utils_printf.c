/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:08:54 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/11 16:11:19 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	print different data-types based on defined formats
*/
int	print_types(va_list ap, t_formats *formats, char **s)
{
	int	np;

	np = 0;
	if (**s == 'c')
		np += print_c(va_arg(ap, int), formats);
	if (**s == 's')
		np += print_s(va_arg(ap, char *), formats);
	if (**s == 'p')
		np += print_p(va_arg(ap, unsigned long), formats);
	if (**s == 'd' || **s == 'i')
		np += print_di(va_arg(ap, int), formats);
	if (**s == 'u')
		np += print_u(va_arg(ap, unsigned int), formats);
	if (**s == 'x' || **s == 'X')
		np += print_x(va_arg(ap, unsigned int), formats, **s);
	if (**s == '%')
		np += print_c('%', formats);
	return (np);
}

/*
	Get all possible flags for formats of data types
	and save it into formats tructures.
	s --> *s --> **s
	any change in the pointer *s can be saved and updated in s
	"-0." & '# +'
*/
void	get_flags(t_formats *formats, char **s)
{
	while (ft_strchr("-0# +", **s) != 0)
	{
		if (**s == '-')
			formats->minus = 1;
		if (**s == '0')
			formats->zero = 1;
		if (**s == '#')
			formats->sharp = 1;
		if (**s == ' ')
			formats->space = 1;
		if (**s == '+')
			formats->plus = 1;
		(*s)++;
	}
}

/*
	ascii to integer conversion to get numbers of width or precision
*/
void	get_width_prcn(int *width, char **s)
{
	while (**s >= '0' && **s <= '9')
	{
		*width = *width * 10 + (**s - '0');
		(*s)++;
	}
}
