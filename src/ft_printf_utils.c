/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 02:08:47 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/10 18:00:20 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	check(const char *s, char c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int	write_print(t_data *data, int c)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	data->chars_written++;
	return (1);
}

int	string_print(t_data *data, const char *str)
{
	int	i;

	i = 0;
	if (data->format.precision_value == 0)
		return (0);
	if (data->format.precision_value)
	{
		while (i++ < data->format.precision_value)
		{
			write_print(data, *str);
			str++;
			if (!*str)
				return (0);
		}
	}
	else
	{
		while (*str)
		{
			if (write_print(data, *str) == -1)
				return (-1);
			str++;
		}
	}
	return (0);
}

void	fill_space(t_data *data, const char c, int size)
{
	int	i;

	i = 0;
	while(i < size)
	{
		if (write_print(data, c) == -1)
			return ;
		i++;
	}
}

void	zero_space(t_data *data, int size)
{
	if (data->format.zero)
		fill_space(data, '0', size);
	else
		fill_space(data, ' ', size);
	return ;
}

void	str_null(t_data *data)
{
	char	*str;

	str = "(null)";
	string_print(data, str);
	return ;
}

int	numlen(long long nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}
