/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_unint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:39:33 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/12 00:32:24 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	print_unint_strct(t_data *data, long long nbr, int width)
{
	if (data->format.left_justified)
	{
		print_prec_zero(data);
		print_nbr(data, nbr);
		if (width > 0)
			zero_space(data, width);
	}
	else
	{
		if (width > 0)
			zero_space(data, width);
		print_prec_zero(data);
		print_nbr(data, nbr);
	}
}

void	ft_printf_unint(t_data *data, unsigned int nbr)
{
	int	width;
	int	num_len;

	num_len = numlen(nbr);
	width = data->format.width_value - num_len;
	if (data->format.precision_value != -1)
	{
		if (data->format.precision_value > num_len)
			width -= data->format.precision_value - num_len;
		if (width < 0)
			width = 0;
	}
	if (data->format.precision_value > 0)
		data->format.precision_value -= num_len;
	if (data->format.precision_value < 0)
		data->format.precision_value = 0;
	print_unint_strct(data, nbr, width);
}