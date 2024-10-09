/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:30:00 by assistant         #+#    #+#             */
/*   Updated: 2024/10/10 00:08:39 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(long n)
{
	char	*str;
	long	tmp;
	int		len;
	int		neg;

	tmp = n;
	len = (n <= 0);
	while (tmp && ++len)
		tmp /= 10;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	neg = (n < 0);
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[--len] = '0' + (neg ? -(n % 10) : n % 10);
		n /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}

char	*ft_uitoa_base(unsigned long n, int base, int uppercase)
{
	char	*str;
	char	*digits;
	unsigned long	tmp;
	int		len;

	digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	tmp = n;
	len = 1;
	while (tmp /= base)
		len++;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = digits[n % base];
		n /= base;
	}
	return (str);
}

int	ft_apply_width(char **str, t_format *f)
{
	int		len;
	int		width;
	char	pad_char;
	char	*padding;
	char	*new_str;

	len = ft_strlen(*str);
	width = f->width > len ? f->width - len : 0;
	if (width <= 0)
		return (0);
	pad_char = (f->flags & FLAG_ZERO && !(f->flags & FLAG_MINUS)) ? '0' : ' ';
	padding = (char *)malloc(width + 1);
	if (!padding)
		return (-1);
	for (int i = 0; i < width; i++)
		padding[i] = pad_char;
	padding[width] = '\0';
	if (f->flags & FLAG_MINUS)
		new_str = ft_strjoin_free(*str, padding);
	else
		new_str = ft_strjoin_free(padding, *str);
	if (!new_str)
		return (-1);
	*str = new_str;
	return (0);
}

int	ft_apply_precision(char **str, t_format *f)
{
	int		len;
	int		prec;
	char	*new_str;
	int		is_negative;

	if (!(f->flags & FLAG_DOT))
		return (0);
	len = ft_strlen(*str);
	prec = f->precision;
	if (f->specifier == 's')
	{
		if (prec < len)
		{
			new_str = (char *)malloc(prec + 1);
			if (!new_str)
				return (-1);
			for (int i = 0; i < prec; i++)
				new_str[i] = (*str)[i];
			new_str[prec] = '\0';
			free(*str);
			*str = new_str;
		}
	}
	else if (f->specifier == 'd' || f->specifier == 'i' ||
			f->specifier == 'u' || f->specifier == 'x' ||
			f->specifier == 'X')
	{
		is_negative = (**str == '-');
		if (is_negative)
		{
			(*str)++;
			len--;
		}
		if (prec > len)
		{
			new_str = (char *)malloc(prec + is_negative + 1);
			if (!new_str)
				return (-1);
			for (int i = 0; i < prec - len; i++)
				new_str[i] = '0';
			for (int i = 0; i < len; i++)
				new_str[prec - len + i] = (*str)[i];
			if (is_negative)
				new_str[0] = '-';
			new_str[prec + is_negative] = '\0';
			if (is_negative)
				(*str)--;
			free(*str);
			*str = new_str;
		}
		else if (is_negative)
		{
			(*str)--;
		}
	}
	return (0);
}
