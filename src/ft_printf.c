/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:56:36 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/09 01:17:08 by ktiomico         ###   ########.fr       */
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
/*
#include <stdio.h>

int	main(void)
{
	int	n;
	char c = 'c';
	char *h	= "this is a string";
	void *p;
	int	size;
	char *b = "ft_";
	n = 42;
	p = &n;

	ft_printf("The difference of return value between ft_printf and printf\n");
	ft_printf("should be 3, for the extra \"%s\" and also +1 on both for \\n\n", b);
	ft_printf("|------------------------------------------------------------|\n");
	ft_printf("|                        CHARACTERS                          |\n");
	ft_printf("|------------------------------------------------------------|\n");
	size = ft_printf("ft_printf: %c\n", c);
	ft_printf("return: %d\n", size);
	size = printf("printf: %c\n", c);
	printf("return: %d\n", size);
	ft_printf("|------------------------------------------------------------|\n");
	ft_printf("|                          STRINGS                           |\n");
	ft_printf("|------------------------------------------------------------|\n");
	size = ft_printf("ft_printf: %s\n", h);
	ft_printf("return: %d\n", size);
	size = printf("printf: %s\n", h);
	printf("return: %d\n", size);
	ft_printf("|------------------------------------------------------------|\n");
	ft_printf("|                           ADDRESS                          |\n");
	ft_printf("|------------------------------------------------------------|\n");
	size = ft_printf("ft_printf: %p\n", p);
	ft_printf("return: %d\n", size);
	size = printf("printf: %p\n", p);
	printf("return: %d\n", size);
	ft_printf("|------------------------------------------------------------|\n");
	ft_printf("|                          DECIMALS                          |\n");
	ft_printf("|------------------------------------------------------------|\n");
	size = ft_printf("ft_printf: %d\n", 42);
	ft_printf("return: %d\n", size);
	size = printf("printf: %d\n", 42);
	printf("return: %d\n", size);
	ft_printf("|------------------------------------------------------------|\n");
	ft_printf("|                      HEXADECIMAL LOWERCASE                 |\n");
	ft_printf("|------------------------------------------------------------|\n");
	size = ft_printf("ft_printf: %x\n", 123456789);
	ft_printf("return: %d\n", size);
	size = printf("printf: %x\n", 123456789);
	printf("return: %d\n", size);
	ft_printf("|------------------------------------------------------------|\n");
	ft_printf("|                     HEXADECIMAL UPPERCASE                  |\n");
	ft_printf("|------------------------------------------------------------|\n");
	size = ft_printf("ft_printf: %X\n", 123456789);
	ft_printf("return: %d\n", size);
	size = printf("printf: %X\n", 123456789);
	printf("return: %d\n", size);
	ft_printf("|------------------------------------------------------------|\n");
	ft_printf("|                        PERCENTAGE                          |\n");
	ft_printf("|------------------------------------------------------------|\n");
	size = ft_printf("ft_printf: %%\n");
	ft_printf("return: %d\n", size);
	size = printf("printf: %%\n");
	printf("return: %d\n", size);
	ft_printf("|------------------------------------------------------------|\n");
	ft_printf("|                           UNSIGNED                         |\n");
	ft_printf("|------------------------------------------------------------|\n");
}
*/
