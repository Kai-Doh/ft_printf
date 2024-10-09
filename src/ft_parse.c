/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:10:00 by assistant         #+#    #+#             */
/*   Updated: 2024/10/10 00:07:29 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_flags(const char **fmt, t_format *f)
{
	while (**fmt == '-' || **fmt == '0' || **fmt == '#' ||
			**fmt == ' ' || **fmt == '+')
	{
		if (**fmt == '-')
			f->flags |= FLAG_MINUS;
		else if (**fmt == '0')
			f->flags |= FLAG_ZERO;
		else if (**fmt == '#')
			f->flags |= FLAG_HASH;
		else if (**fmt == ' ')
			f->flags |= FLAG_SPACE;
		else if (**fmt == '+')
			f->flags |= FLAG_PLUS;
		(*fmt)++;
	}
	return (0);
}

int	ft_parse_width(const char **fmt, t_format *f, va_list ap)
{
	f->width = 0;
	if (**fmt == '*')
	{
		f->width = va_arg(ap, int);
		(*fmt)++;
	}
	else
	{
		while (**fmt >= '0' && **fmt <= '9')
		{
			f->width = f->width * 10 + (**fmt - '0');
			(*fmt)++;
		}
	}
	return (0);
}

int	ft_parse_precision(const char **fmt, t_format *f, va_list ap)
{
	if (**fmt == '.')
	{
		f->flags |= FLAG_DOT;
		f->precision = 0;
		(*fmt)++;
		if (**fmt == '*')
		{
			f->precision = va_arg(ap, int);
			(*fmt)++;
		}
		else
		{
			while (**fmt >= '0' && **fmt <= '9')
			{
				f->precision = f->precision * 10 + (**fmt - '0');
				(*fmt)++;
			}
		}
	}
	return (0);
}

int	ft_parse_format(const char **fmt, t_format *f, va_list ap)
{
	f->flags = 0;
	f->width = 0;
	f->precision = -1;
	if (ft_parse_flags(fmt, f) == -1)
		return (-1);
	if (ft_parse_width(fmt, f, ap) == -1)
		return (-1);
	if (ft_parse_precision(fmt, f, ap) == -1)
		return (-1);
	if (**fmt == 'c' || **fmt == 's' || **fmt == 'p' ||
		**fmt == 'd' || **fmt == 'i' || **fmt == 'u' ||
		**fmt == 'x' || **fmt == 'X' || **fmt == '%')
	{
		f->specifier = **fmt;
		(*fmt)++;
	}
	else
		return (-1);
	return (0);
}
