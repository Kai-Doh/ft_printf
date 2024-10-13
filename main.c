/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:50:23 by ktiomico          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/12 16:51:01 by ktiomico         ###   ########.fr       */
=======
/*   Updated: 2024/10/13 14:52:29 by ktiomico         ###   ########.fr       */
>>>>>>> origin/bonus
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

// Declare your ft_printf function here
// For example:
// int ft_printf(const char *format, ...);

int main() {
/*
    printf("[%0d]\n]why does this go down here1", -1);
    printf("[%0d]\n]why does this go down here2", -1);
    printf("[%0d]\n]why does this go down here3", -1);
    ft_printf("[%0d]\n]why does this go down here5", -1);
    ft_printf("[%0d]\n]why does this go down here6", -1);
    ft_printf("[%0d]\n]why does this go down here7", -1);
//weird behavior between printf and ft_printf
*/
//	printf("");
<<<<<<< HEAD
	ft_printf("ft_printf: ");
	int f = ft_printf(" [%.2d] \n", -1);
	ft_printf("   printf: ");
	int	t = printf(" [%.2d] \n", -1);
	ft_printf("return of ft_printf: %d\nreturn of printf: %d\n", f, t);
//	printf("%5%");
=======
	ft_printf(" [%-12d] ", LONG_MIN);
	printf(" [%-12ld] ", LONG_MIN);
//	printf("%5%");  %-3d   1    "[%-1d]", 0
>>>>>>> origin/bonus

//	ft_printf("return of printf: %d\nreturn of ft_printf: \n", b);
  //  return (0);
}
// mandatory p 0
// - 27 29
//
//	printf("[%.3d]\n", -1);
//	ft_printf("[%.3d]\n", -1);
//	printf("[%.4d]\n", -1);
//	ft_printf("[%.4d]\n", -1);

// string with width and precision didnt work
// width 10 %d didnt work
