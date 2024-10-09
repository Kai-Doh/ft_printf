/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:33:13 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/09 16:25:26 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_nbr_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_putunintnbr(unsigned int n)
{
	int	result;

	if (n >= 10)
	{
		result = ft_putunintnbr(n / 10);
		if (result == -1)
			return (-1);
		result = ft_putunintnbr(n % 10);
		if (result == -1)
			return (-1);
	}
	else
	{
		result = printchar(n + '0');
		if (result == -1)
			return (-1);
	}
	return (1);
}

int	ft_printf_unint(unsigned int n)
{
	int	len;
	int	result;

	len = ft_nbr_len(n);
	result = ft_putunintnbr(n);
	if (result == -1)
		return (-1);
	return (len);
}
