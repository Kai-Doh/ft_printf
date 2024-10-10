/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:50:23 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/11 01:30:27 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
int	main(void)
{
	ft_printf("Test 4: %#-4.3x\n", 233355);
	printf("Test 4: %#-4.3x\n", 233355);
	ft_printf("Left alignment: %-8.5x\n", 255);

	ft_printf("-------------------------------------------------------------\n");
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("Simple character: %c\n", 'A');
	ft_printf("Null character: %c\n", '\0');
	ft_printf("Character with width: %5c\n", 'B');
	ft_printf("Character with left alignment: %-5c\n", 'C');
	ft_printf("Character with zero padding (should be ignored): %05c\n", 'D');
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("Simple string: %s\n", "Hello, World!");
	ft_printf("Empty string: %s\n", "");
	ft_printf("Null string: %s\n", NULL); // If your ft_printf handles NULL strings
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("String with width: %20s\n", "Hello");
	ft_printf("String with left alignment: %-20s\n", "Hello");
	ft_printf("String with precision: %.5s\n", "Hello, World!");
	ft_printf("String with width and precision: %10.5s\n", "Hello, World!"); // did not work
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("-------------------------------------------------------------\n");
	int a = 42;
	ft_printf("Pointer to integer a: %p\n", &a);
	ft_printf("Null pointer: %p\n", NULL);
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("Positive integer: %d\n", 123);
	ft_printf("Negative integer: %d\n", -456);
	ft_printf("Zero: %d\n", 0);
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("Width 10: %10d\n", 123); // did not work
	ft_printf("Precision 5: %.5d\n", 123); // did not work
	ft_printf("Width and precision: %10.5d\n", 123); // did not work
	ft_printf("Left alignment: %-10d\n", 123); // got inverted
	ft_printf("Zero padding: %010d\n", 123); // got inverted
	ft_printf("Zero padding with precision: %010.5d\n", 123);
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("Space flag with positive: % d\n", 123);
	ft_printf("Plus flag with positive: %+d\n", 123);
	ft_printf("Space flag with negative: % d\n", -123);
	ft_printf("Plus flag with negative: %+d\n", -123);
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("Unsigned integer: %u\n", 123);
	ft_printf("Unsigned integer max: %u\n", 4294967295u); // Assuming 32-bit unsigned int
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("Width 10: %10u\n", 123);
	ft_printf("Precision 5: %.5u\n", 123);
	ft_printf("Width and precision: %10.5u\n", 123);
	ft_printf("Left alignment: %-10u\n", 123);
	ft_printf("Zero padding: %010u\n", 123);
	ft_printf("Width 10: %10u\n", 123);
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("Precision 5: %.5u\n", 123);
	ft_printf("Width and precision: %10.5u\n", 123);
	ft_printf("Left alignment: %-10u\n", 123);
	ft_printf("Zero padding: %010u\n", 123);
	ft_printf("Mixed: %+-10.5d\n", 123);
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("Mixed: % 0+10.5d\n", 123);
	ft_printf("Hex with all flags: %#0-10.5x\n", 255);
	ft_printf("Unsigned with flags: %+10u\n", 123); // Note: '+' flag has no effect on unsigned
	ft_printf("Width *: %*d\n", 10, 123);
	ft_printf("Precision *: %.*d\n", 5, 123);
	ft_printf("Width and precision *: %*.*d\n", 10, 5, 123);
	ft_printf("Hello %s, your score is %+05d out of %d.\n", "Alice", 42, 100);
	ft_printf("Memory address: %20p\n", &a);
	ft_printf("Hex dump: %#08x %#08x %#08x\n", 0xDEADBEEF, 0xFEEDC0DE, 0xBAADF00D);
}
// string with width and precision didnt work
// width 10 %d didnt work
