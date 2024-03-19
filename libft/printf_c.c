/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:59:58 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/11 16:10:21 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* print_c:
rules:
// Test cases:
// printf("[%%]\n");					[%]					
// printf("[%2%]\n");					[ %]
// printf("[%-2%]\n");					[% ]
// printf("[%02%]\n");					[0%]
// printf("[%-02%]\n");					[% ]
*/

int	ft_putxstr(char *s, int len, int *err)
{
	*err = write(1, s, len);
	if (*err < 0)
		return (*err);
	return (len);
}

int	ft_putnchar(char c, int n, int *err)
{
	int	i;

	i = 0;
	if (n <= 0)
		return (0);
	else
	{
		while (i < n)
		{
			*err = write(1, &c, 1);
			if (*err < 0)
				return (*err);
			i++;
		}
	}
	return (n);
}

static int	print_c1(char c, int *err, int n_blank)
{
	int	np;

	np = 0;
	np += ft_putnchar(c, 1, err);
	if (*err < 0)
		return (*err);
	np += ft_putnchar(' ', n_blank, err);
	if (*err < 0)
		return (*err);
	return (np);
}

static int	print_c2(t_formats *formats, char c, int n_blank)
{
	int	np;

	np = 0;
	if (formats->zero == 1)
	{
		np += ft_putnchar('0', n_blank, &(formats->err));
		if (formats->err < 0)
			return (formats->err);
	}
	else if (formats->zero == 0)
	{
		np += ft_putnchar(' ', n_blank, &(formats->err));
		if (formats->err < 0)
			return (formats->err);
	}
	np += ft_putnchar(c, 1, &(formats->err));
	if (formats->err < 0)
		return (formats->err);
	return (np);
}

int	print_c(char c, t_formats *formats)
{
	int	n_blank;
	int	np;

	np = 0;
	n_blank = formats->width - 1;
	if (formats->minus == 1)
		np += print_c1(c, &(formats->err), n_blank);
	else
		np += print_c2(formats, c, n_blank);
	if (formats->err < 0)
		return (formats->err);
	return (np);
}
