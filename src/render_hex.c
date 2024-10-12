/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:37:43 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/12 12:08:59 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	print_hex(t_data *data, unsigned long long nbr)
{
	if (nbr >= 16)
	{
		print_hex(data, nbr / 16);
		print_hex(data, nbr % 16);
	}
	else
	{
		if (nbr < 10)
			write_print(data, nbr + '0');
		else
			write_print(data, nbr - 10 + 'a');
	}
}

void	print_hex_upp(t_data *data, unsigned int nbr)
{
	if (nbr >= 16)
	{
		print_hex_upp(data, nbr / 16);
		print_hex_upp(data, nbr % 16);
	}
	else
	{
		if (nbr < 10)
			write_print(data, nbr + '0');
		else
			write_print(data, nbr - 10 + 'A');
	}
}

void	format_hex(t_data *data, unsigned int nbr, int width)
{
	if (width > 0)
	{
		if (data->format.left_justified)
		{
			print_hex_hash(data, nbr);
			print_prec_zero(data);
			print_hex(data, nbr);
			zero_space(data, width);
		}
		else
		{
			zero_space(data, width);
			print_hex_hash(data, nbr);
			print_prec_zero(data);
			print_hex(data, nbr);
		}
	}
	else
	{
		print_hex_hash(data, nbr);
		print_prec_zero(data);
		print_hex(data, nbr);
	}
}

void	format_hex_upp(t_data *data, unsigned int nbr, int width)
{
	if (width > 0)
	{
		if (data->format.left_justified)
		{
			print_hex_hashup(data, nbr);
			print_prec_zero(data);
			print_hex_upp(data, nbr);
			zero_space(data, width);
		}
		else
		{
			zero_space(data, width);
			print_hex_hashup(data, nbr);
			print_prec_zero(data);
			print_hex_upp(data, nbr);
		}
	}
	else
	{
		print_hex_hashup(data, nbr);
		print_prec_zero(data);
		print_hex_upp(data, nbr);
	}
}

void	ft_printf_hex(t_data *data, unsigned int nbr)
{
	int	width;
	int	count_hex;

	width = data->format.width_value;
	count_hex = hex_length(nbr);
	if (data->format.precision_value > 0)
		data->format.precision_value -= count_hex;
	if (data->format.precision_value < 0)
		data->format.precision_value = 0;
	if (data->format.hashtag == 1 && nbr != 0)
		count_hex += 2;
	if (width > 0)
		width -= count_hex + data->format.precision_value;
	if (width < 0)
		width = 0;
	if (data->format.specifier == 'X')
		format_hex_upp(data, nbr, width);
	else
		format_hex(data, nbr, width);
}
