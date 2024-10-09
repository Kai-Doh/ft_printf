/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:15:00 by assistant         #+#    #+#             */
/*   Updated: 2024/10/10 00:07:48 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_conversion(t_format *f, va_list ap, int *len)
{
	if (f->specifier == 'c')
		return (ft_print_char(f, ap, len));
	else if (f->specifier == 's')
		return (ft_print_string(f, ap, len));
	else if (f->specifier == 'p')
		return (ft_print_pointer(f, ap, len));
	else if (f->specifier == 'd' || f->specifier == 'i')
		return (ft_print_number(f, ap, len));
	else if (f->specifier == 'u')
		return (ft_print_unsigned(f, ap, len));
	else if (f->specifier == 'x')
		return (ft_print_hex(f, ap, 0, len));
	else if (f->specifier == 'X')
		return (ft_print_hex(f, ap, 1, len));
	else if (f->specifier == '%')
	{
		if (ft_putchar('%') == -1)
			return (-1);
		(*len)++;
	}
	return (0);
}

int	ft_print_char(t_format *f, va_list ap, int *len)
{
	char	c;
	char	*str;
	int		res;

	c = va_arg(ap, int);
	str = (char *)malloc(2);
	if (!str)
		return (-1);
	str[0] = c;
	str[1] = '\0';
	if (ft_apply_width(&str, f) == -1)
		return (-1);
	res = ft_putstr(str);
	free(str);
	if (res == -1)
		return (-1);
	*len += res;
	return (0);
}

int	ft_print_string(t_format *f, va_list ap, int *len)
{
	char	*s;
	char	*str;
	int		res;

	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	str = ft_strdup(s);
	if (!str)
		return (-1);
	if (ft_apply_precision(&str, f) == -1)
		return (-1);
	if (ft_apply_width(&str, f) == -1)
		return (-1);
	res = ft_putstr(str);
	free(str);
	if (res == -1)
		return (-1);
	*len += res;
	return (0);
}

int	ft_print_pointer(t_format *f, va_list ap, int *len)
{
	char			*str;
	unsigned long	n;
	int				res;

	n = (unsigned long)va_arg(ap, void *);
	str = ft_uitoa_base(n, 16, 0);
	if (!str)
		return (-1);
	str = ft_strjoin_free(ft_strdup("0x"), str);
	if (!str)
		return (-1);
	if (ft_apply_width(&str, f) == -1)
		return (-1);
	res = ft_putstr(str);
	free(str);
	if (res == -1)
		return (-1);
	*len += res;
	return (0);
}
