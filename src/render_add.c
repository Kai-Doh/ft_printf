/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:38:21 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/11 00:10:55 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	hex_length(unsigned long long n)
{
	int	length;

	length = 1;
	if (n == 0)
		return (1);
	while (n >= 16)
	{
		n /= 16;
		length++;
	}
	return (length);
}

void	print_nil(t_data *data)
{
	char	*str;
	int		i;

	str = "(nil)";
	i = 0;
	while (str[i])
	{
		write_print(data, str[i]);
		i++;
	}
	return ;
}

void	format_add(t_data *data, unsigned long long address, int width)
{
	if (address == 0)
		print_nil(data);
	else if (width > 1 && address)
	{
		if (data->format.left_justified)
		{
			write_print(data, '0');
			write_print(data, 'x');
			print_hex(data, address);
			fill_space(data, ' ', width);
		}
		else
		{
			fill_space(data, ' ', width);
			write_print(data, '0');
			write_print(data, 'x');
			print_hex(data, address);
		}
	}
	else
	{
		write_print(data, '0');
		write_print(data, 'x');
		print_hex(data, address);
	}
}

void	ft_printf_add(t_data *data, unsigned long long address)
{
	int	width;
	int	count_hex;

	count_hex = hex_length(address);
	width = data->format.width_value - count_hex + 2;
	format_add(data, address, width);
}
