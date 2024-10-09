/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:35:00 by assistant         #+#    #+#             */
/*   Updated: 2024/10/10 00:14:43 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int ret1, ret2;

	ret1 = ft_printf("Hello %s!\n", "World");
	ret2 = printf("Hello %s!\n", "World");
	printf("ft_printf returned %d, printf returned %d\n", ret1, ret2);

	ret1 = ft_printf("Character: %c\n", 'A');
	ret2 = printf("Character: %c\n", 'A');
	printf("ft_printf returned %d, printf returned %d\n", ret1, ret2);

	ret1 = ft_printf("Integer: %d\n", 42);
	ret2 = printf("Integer: %d\n", 42);
	printf("ft_printf returned %d, printf returned %d\n", ret1, ret2);

	ret1 = ft_printf("Unsigned: %u\n", 3000000000U);
	ret2 = printf("Unsigned: %u\n", 3000000000U);
	printf("ft_printf returned %d, printf returned %d\n", ret1, ret2);

	ret1 = ft_printf("Hex lower: %x\n", 255);
	ret2 = printf("Hex lower: %x\n", 255);
	printf("ft_printf returned %d, printf returned %d\n", ret1, ret2);

	ret1 = ft_printf("Hex upper: %X\n", 255);
	ret2 = printf("Hex upper: %X\n", 255);
	printf("ft_printf returned %d, printf returned %d\n", ret1, ret2);

	ret1 = ft_printf("Pointer: %p\n", main);
	ret2 = printf("Pointer: %p\n", main);
	printf("ft_printf returned %d, printf returned %d\n", ret1, ret2);

	ret1 = ft_printf("Percent: %%\n");
	ret2 = printf("Percent: %%\n");
	printf("ft_printf returned %d, printf returned %d\n", ret1, ret2);

	ret1 = ft_printf("Width and precision: %10.5d\n", 123);
	ret2 = printf("Width and precision: %10.5d\n", 123);
	printf("ft_printf returned %d, printf returned %d\n", ret1, ret2);

	ret1 = ft_printf("Flags: %-+10d\n", 123);
	ret2 = printf("Flags: %-+10d\n", 123);
	printf("ft_printf returned %d, printf returned %d\n", ret1, ret2);

	ret1 = ft_printf("Alternate form: %#x\n", 255);
	ret2 = printf("Alternate form: %#x\n", 255);
	printf("ft_printf returned %d, printf returned %d\n", ret1, ret2);

	return 0;
}
