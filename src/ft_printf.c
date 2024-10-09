/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:56:36 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/09 21:26:30 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	format(char type, va_list args)
{
	int	result;

	if (type == 'c')
		result = printchar(va_arg(args, int));
	else if (type == 's')
		result = printstr(va_arg(args, char *));
	else if (type == 'p')
		result = ft_printf_ptr(va_arg(args, unsigned long long));
	else if (type == 'd' || type == 'i')
		result = printnbr(va_arg(args, int));
	else if (type == 'u')
		result = ft_printf_unint(va_arg(args, unsigned int));
	else if (type == 'x')
		result = ft_printf_hex(va_arg(args, unsigned int));
	else if (type == 'X')
		result = ft_printf_hexupper(va_arg(args, unsigned int));
	else if (type == '%')
		result = printpercent();
	else
		return (-1);
	if (result == -1)
		return (-1);
	return (result);
}

int	ft_error(va_list *args)
{
	va_end(*args);
	return (-1);
}

int	process_format(const char *type, unsigned int *i, va_list *args)
{
	int	result;

	result = format(type[*i + 1], *args);
	if (result != -1)
		(*i)++;
	else
		result = ft_error(args);
	return (result);
}

int	process_char(const char c, va_list *args)
{
	int	result;

	result = printchar(c);
	if (result == -1)
		return (ft_error(args));
	return (1);
}

int	ft_printf(const char *type, ...)
{
	va_list			args;
	unsigned int	i;
	int				print_count;
	int				result;

	print_count = 0;
	va_start(args, type);
	i = 0;
	while (type[i])
	{
		if (type[i] == '%')
			result = process_format(type, &i, &args);
		else
			result = process_char(type[i], &args);
		if (result == -1)
			return (-1);
		print_count += result;
		i++;
	}
	va_end(args);
	return (print_count);
}
