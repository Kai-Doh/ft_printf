/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:46:29 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/09 09:48:13 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

#include <stdio.h>

int	main(void)
{
	int	n;
	unsigned int u;
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
	size = ft_printf("ft_printf: %d\n", -n);
	ft_printf("return: %d\n", size);
	size = printf("printf: %d\n", -n);
	printf("return: %d\n", size);
	ft_printf("|------------------------------------------------------------|\n");
	ft_printf("|                           UNSIGNED                         |\n");
	ft_printf("|------------------------------------------------------------|\n");
	u = 4294967295;
	size = ft_printf("ft_printf: %u\n", u);
	ft_printf("return: %d\n", size);
	size = printf("printf: %u\n", u);
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
	return (0);
}
