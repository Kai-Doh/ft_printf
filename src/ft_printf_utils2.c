/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 00:42:48 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/13 17:41:24 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	print_hex_hashup(t_data *data, unsigned int nbr)
{
	if (data->format.hashtag == 1 && nbr > 0)
	{
		write_print(data, '0');
		write_print(data, 'X');
	}
}

void	print_hex_hash(t_data *data, unsigned int nbr)
{
	if (data->format.hashtag == 1 && nbr > 0)
	{
		write_print(data, '0');
		write_print(data, 'x');
	}
}

void	zero_space(t_data *data, int size)
{
	while (size > 0)
	{
		if (data->format.zero)
			write_print(data, '0');
		else
			write_print(data, ' ');
		size--;
	}
	return ;
}

void	print_prec_zero_d(t_data *data, int precision)
{
	while (precision > 0)
	{
		write_print(data, '0');
		precision--;
	}
}

void	sign_space(t_data *data, long long nbr)
{
	if ((nbr >= 0 && data->format.plus && data->format.space)
		|| (nbr >= 0 && data->format.plus))
		write_print(data, '+');
	else if (!data->format.plus && data->format.space && nbr >= 0)
		write_print(data, ' ');
	else if (nbr < 0)
		write_print(data, '-');
}
