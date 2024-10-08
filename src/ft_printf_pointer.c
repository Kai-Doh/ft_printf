/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:49:43 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/08 23:08:41 by ktiomico         ###   ########.fr       */
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

void	ft_put_hex(unsigned long long nbr)
{
	if (nbr >= 16)
	{
		ft_put_hex(nbr / 16);
		ft_put_hex(nbr % 16);
	}
	else
	{
		if (nbr < 10)
			ft_putchar_fd(nbr + '0', 1);
		else
			ft_putchar_fd(nbr - 10 + 'a', 1);
	}
}

int	ft_printf_ptr(unsigned long long address)
{
	int	print_count;

	print_count = 0;
	print_count += write(1, "0x", 2);
	if (address == 0)
		print_count += write(1, "0", 1);
	else
	{
		ft_put_hex(address);
		print_count += ft_ptr_len(address);
	}
	return (print_count);
}
