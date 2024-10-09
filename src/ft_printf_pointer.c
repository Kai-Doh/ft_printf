/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:49:43 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/09 21:23:28 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_ptr_len(unsigned long long address)
{
	int	len;

	len = 0;
	if (address == 0)
		return (1);
	while (address)
	{
		address /= 16;
		len++;
	}
	return (len);
}

int	ft_printf_ptr(unsigned long long address)
{
	int	print_count;
	int	result;

	if (address == 0)
		return (printstr("(nil)"));
	print_count = write(1, "0x", 2);
	if (print_count == -1)
		return (-1);
	result = ft_put_hex(address);
	if (result == -1)
		return (-1);
	return (print_count + ft_ptr_len(address));
}
