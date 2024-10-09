/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:33:13 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/09 09:36:55 by ktiomico         ###   ########.fr       */
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

void	ft_putunintnbr(unsigned int n)
{
	if (n >= 10)
	{
		ft_putunintnbr(n / 10);
		ft_putunintnbr(n % 10);
	}
	else
		ft_putchar_fd(n + '0', 1);
}

int	ft_printf_unint(unsigned int n)
{
	int		len;

	len = 0;
	ft_putunintnbr(n);
	len += ft_nbr_len(n);
	return (len);
}
