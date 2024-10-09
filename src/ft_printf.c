/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:56:36 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/09 09:48:08 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	format(char type, va_list args)
{
	int	print_count;

	print_count = 0;
	if (type == 'c')
		print_count += printchar(va_arg(args, int));
	else if (type == 's')
		print_count += printstr(va_arg(args, char *));
	else if (type == 'p')
		print_count += ft_printf_ptr(va_arg(args, unsigned long long));
	else if (type == 'd' || type == 'i')
		print_count += printnbr(va_arg(args, int));
	else if (type == 'u')
		print_count += ft_printf_unint(va_arg(args, unsigned int));
	else if (type == 'x')
		print_count += ft_printf_hex(va_arg(args, unsigned int));
	else if (type == 'X')
		print_count += ft_printf_hexupper(va_arg(args, unsigned int));
	else if (type == '%')
		print_count += printpercent();
	return (print_count);
}

int	ft_printf(const char *type, ...)
{
	va_list			args;
	unsigned int	i;
	int				print_count;

	print_count = 0;
	va_start(args, type);
	i = 0;
	while (type[i])
	{
		if (type[i] == '%')
		{
			print_count += format(type[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar_fd(type[i], 1);
			print_count++;
		}
		i++;
	}
	va_end(args);
	return (print_count);
}
