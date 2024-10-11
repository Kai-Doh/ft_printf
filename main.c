/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:50:23 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/11 15:42:24 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdio.h>   // For standard printf (used for comparison)
#include <limits.h>  // For INT_MAX, INT_MIN, UINT_MAX
#include <stddef.h>  // For NULL

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
	printf(" [%-2p] \n", (void *)-2147483648);
	ft_printf(" [%-2p] \n", (void *)-2147483648);
    return (0);
}

//	printf("[%.3d]\n", -1);
//	ft_printf("[%.3d]\n", -1);
//	printf("[%.4d]\n", -1);
//	ft_printf("[%.4d]\n", -1);

// string with width and precision didnt work
// width 10 %d didnt work
