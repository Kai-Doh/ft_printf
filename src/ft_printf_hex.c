/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:19:54 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/09 21:23:06 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf_hex(unsigned int n)
{
	int	len;

	if (ft_put_hex(n) == -1)
		return (-1);
	len = ft_ptr_len(n);
	return (len);
}

int	ft_printf_hexupper(unsigned int n)
{
	int	len;

	len = 0;
	if (ft_put_hexupper(n) == -1)
		return (-1);
	len += ft_ptr_len(n);
	return (len);
}

int	ft_put_hexupper(unsigned long long nbr)
{
	if (nbr >= 16)
	{
		if (ft_put_hexupper(nbr / 16) == -1)
			return (-1);
		if (ft_put_hexupper(nbr % 16) == -1)
			return (-1);
	}
	else
	{
		if (nbr < 10)
		{
			if (printchar(nbr + '0') == -1)
				return (-1);
		}
		else
		{
			if (printchar(nbr - 10 + 'A') == -1)
				return (-1);
		}
	}
	return (1);
}

int	ft_put_hex(unsigned long long nbr)
{
	if (nbr >= 16)
	{
		if (ft_put_hex(nbr / 16) == -1)
			return (-1);
		if (ft_put_hex(nbr % 16) == -1)
			return (-1);
	}
	else
	{
		if (nbr < 10)
		{
			if (printchar(nbr + '0') == -1)
				return (-1);
		}
		else
		{
			if (printchar(nbr - 10 + 'a') == -1)
				return (-1);
		}
	}
	return (1);
}
