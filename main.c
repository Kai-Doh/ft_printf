/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:50:23 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/10 17:43:53 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>
int	main(void)
{
	ft_printf("zero spacing: %-020.0s\n", "World!");
	ft_printf("blank spacing: %20s\n", "World!");
	ft_printf("zero spacing left: %-20s\n", "World!");
	ft_printf("blank spacing left: %020s\n", "World!");
	ft_printf("int positive plus: %+ 020i\n", 42);
	ft_printf("zero spacing: %.2002s\n", "World!");
	printf("zero spacing: %.2d\n", 41234);
}
