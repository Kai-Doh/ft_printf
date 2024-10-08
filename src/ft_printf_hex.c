/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 23:11:48 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/08 23:40:54 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf_hex(unsigned int n)
{
	int		len;

	len = 0;
	ft_put_hex(n);
	ft_ptr_len(n);
	return (len);
}

int	ft_printf_hexupper(unsigned int n)
{
	int		len;

	len = 0;
	ft_put_hexupper(n);
	ft_ptr_len(n);
	return (len);
}

void	ft_put_hexupper(unsigned long long nbr)
{
	if (nbr >= 16)
	{
		ft_put_hexupper(nbr / 16);
		ft_put_hexupper(nbr % 16);
	}
	else
	{
		if (nbr < 10)
			ft_putchar_fd(nbr + '0', 1);
		else
			ft_putchar_fd(nbr - 10 + 'A', 1);
	}
}
