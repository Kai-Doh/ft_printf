/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:18:46 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/10 17:51:59 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	render_format(t_data *data)
{
	char	type;

	type = data->format.specifier;
	if ('%' == data->format.specifier)
		print_char(data, '%');
	else if ('c' == data->format.specifier)
		print_char(data, va_arg(data->ap, int));
	else if ('s' == data->format.specifier)
		print_str(data, va_arg(data->ap, char *));
	else if ('d' == data->format.specifier || 'i' == data->format.specifier)
		ft_printf_d(data, va_arg(data->ap, int));
/*	else if ('u' == specifier)
	else if ('x' == specifier || 'X' == specifier)
	else if ('p' == specifier) */
}

static int	init_data(t_data *data)
{
	data->chars_written = 0;
	return (OK);
}
int	ft_printf(const char *format, ...)
{
	t_data	data;

	va_start(data.ap, format);
	if (init_data(&data))
		return (-1);
	while (*format)
	{
		if (*format == '%' && *(++format))
		{
			if (format_parsing(&data, &format))
				return (PARSE_ERROR);
			render_format(&data);
		}
		else
			if (write_print(&data, *format) == -1)
				return (-1);
		++format;
	}
	va_end(data.ap);
	return (data.chars_written);
}
