/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:05:00 by assistant         #+#    #+#             */
/*   Updated: 2024/10/10 00:07:10 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			len;
	t_format	f;
	int			ret;

	len = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1))
		{
			fmt++;
			if (ft_parse_format(&fmt, &f, ap) == -1)
				return (-1);
			ret = ft_handle_conversion(&f, ap, &len);
			if (ret == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar(*fmt++) == -1)
				return (-1);
			len++;
		}
	}
	va_end(ap);
	return (len);
}
