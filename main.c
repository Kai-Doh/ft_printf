/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:50:23 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/14 17:17:49 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	m;
	int	n;
	void *p;

	p = &n;
	printf("---printf:");
	m = printf("[% d]", 14);
	printf("\n");
	ft_printf("ft_printf:");
	n = ft_printf("[% d]", 14);
	ft_printf("\n");
	ft_printf("return of printf: %d\n", m);
	ft_printf("return of ft_printf: %d\n", n);
	return (0);
}
/*
    printf("[%0d]\n]why does this go down here1", -1);
    printf("[%0d]\n]why does this go down here2", -1);
    printf("[%0d]\n]why does this go down here3", -1);
    ft_printf("[%0d]\n]why does this go down here5", -1);
    ft_printf("[%0d]\n]why does this go down here6", -1);
    ft_printf("[%0d]\n]why does this go down here7", -1);
*/
