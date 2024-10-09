/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:20:00 by assistant         #+#    #+#             */
/*   Updated: 2024/10/10 00:08:03 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_number(t_format *f, va_list ap, int *len)
{
	char	*str;
	long	n;
	int		res;

	n = va_arg(ap, int);
	str = ft_itoa(n);
	if (!str)
		return (-1);
	if (ft_apply_precision(&str, f) == -1)
		return (-1);
	if (n >= 0 && (f->flags & FLAG_PLUS))
		str = ft_strjoin_free(ft_strdup("+"), str);
	else if (n >= 0 && (f->flags & FLAG_SPACE))
		str = ft_strjoin_free(ft_strdup(" "), str);
	if (!str)
		return (-1);
	if (ft_apply_width(&str, f) == -1)
		return (-1);
	res = ft_putstr(str);
	free(str);
	if (res == -1)
		return (-1);
	*len += res;
	return (0);
}

int	ft_print_unsigned(t_format *f, va_list ap, int *len)
{
	char			*str;
	unsigned int	n;
	int				res;

	n = va_arg(ap, unsigned int);
	str = ft_uitoa_base(n, 10, 0);
	if (!str)
		return (-1);
	if (ft_apply_precision(&str, f) == -1)
		return (-1);
	if (ft_apply_width(&str, f) == -1)
		return (-1);
	res = ft_putstr(str);
	free(str);
	if (res == -1)
		return (-1);
	*len += res;
	return (0);
}

int	ft_print_hex(t_format *f, va_list ap, int uppercase, int *len)
{
	char			*str;
	unsigned int	n;
	int				res;

	n = va_arg(ap, unsigned int);
	str = ft_uitoa_base(n, 16, uppercase);
	if (!str)
		return (-1);
	if (f->flags & FLAG_HASH && n != 0)
	{
		if (uppercase)
			str = ft_strjoin_free(ft_strdup("0X"), str);
		else
			str = ft_strjoin_free(ft_strdup("0x"), str);
		if (!str)
			return (-1);
	}
	if (ft_apply_precision(&str, f) == -1)
		return (-1);
	if (ft_apply_width(&str, f) == -1)
		return (-1);
	res = ft_putstr(str);
	free(str);
	if (res == -1)
		return (-1);
	*len += res;
	return (0);
}
