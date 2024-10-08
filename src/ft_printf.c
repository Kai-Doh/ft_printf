/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:56:36 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/08 23:51:52 by ktiomico         ###   ########.fr       */
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

#include <stdio.h>

int	main(void)
{
	int	n;
	char *h	= "this is a string that was printed using %s on ft_printf";
	void *p;

	n = 42;
	ft_printf("This string was printed using ft_printf\n");
	ft_printf("The following lines are tests to make sure ft_printf works\n");
	ft_printf("for any situations according to the project\n");
	ft_printf("%%%% & %%d \n");
	n = ft_printf("That was a test to make sure %%%% was shown\n");
	ft_printf("the print before was 42 characters so n is: %d\n", n);
	ft_printf("The n = 42 was a coincidence... or was it? hehehe :)\n");
	ft_printf("%s\n", h);
	p = &n;
	ft_printf("The address of n is: %p\n", p);
	printf("This is the address using printf: %p\n", p);
	n = 42424242;
	ft_printf("This is an example of an int (n = 42424242) into hex: %x\n", n);
	ft_printf("This is the same example using %%X: %X\n", n);
	printf("This is the same example using printf: %X\n", n);
}
