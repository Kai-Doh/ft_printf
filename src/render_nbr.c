/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:32:19 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/13 15:07:50 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	struct_int_zero(t_data *data, int nbr)
{
	if (nbr < 0 || data->format.plus || data->format.space)
	{
		sign_space(data, nbr);
		data->format.width_value--;
	}
	if (nbr < 0)
		nbr *= -1;
	data->format.width_value -= numlen(nbr);
	zero_space(data, data->format.width_value);
	print_nbr(data, nbr);
}

void	print_prec(t_data *data, int nbr)
{
	zero_space(data, data->format.width_value);
	sign_space(data, nbr);
	if (data->format.precision_value > 0)
		print_prec_zero(data);
	print_nbr(data, nbr);
}

void	print_prec_left(t_data *data, int nbr)
{
	sign_space(data, nbr);
	if (data->format.precision_value > 0)
		print_prec_zero(data);
	print_nbr(data, nbr);
	zero_space(data, data->format.width_value);
}

void	struct_int_prec(t_data *data, int nbr)
{
	if (nbr < 0 || data->format.plus || data->format.space)
		data->format.width_value--;
	if (data->format.precision_value > numlen(nbr))
		data->format.width_value -= data->format.precision_value;
	else
		data->format.width_value -= numlen(nbr);
	data->format.precision_value -= numlen(nbr);
	if (data->format.left_justified)
		print_prec_left(data, nbr);
	else
		print_prec(data, nbr);
}

void	ft_printf_int(t_data *data, int nbr)
{
	if (data->format.zero == 1)
		struct_int_zero(data, nbr);
	else if (data->format.precision_value > 0)
		struct_int_prec(data, nbr);
	else
	{
		if (nbr < 0 || data->format.plus || data->format.space)
			data->format.width_value--;
		data->format.width_value -= numlen(nbr);
		if (data->format.left_justified)
		{
			sign_space(data, nbr);
			print_nbr(data, nbr);
			zero_space(data, data->format.width_value);
		}
		else
		{
			zero_space(data, data->format.width_value);
			sign_space(data, nbr);
			print_nbr(data, nbr);
		}
	}
}
