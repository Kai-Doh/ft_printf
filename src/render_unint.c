/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_unint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:39:33 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/11 15:16:01 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	print_unint_strct(t_data *data, long long nbr, int width)
{
	if (width > 0)
	{
		if (data->format.left_justified)
		{
			print_prec_zero(data);
			print_nbr(data, nbr);
			zero_space(data, width);
		}
		else
		{
			zero_space(data, width);
			print_prec_zero(data);
			print_nbr(data, nbr);
		}
	}
	else
	{
		print_prec_zero(data);
		print_nbr(data, nbr);
	}
}

void	ft_printf_unint(t_data *data, unsigned int nbr)
{
	int		width;

	width = data->format.width_value - numlen(nbr);
	if (data->format.precision_value != -1)
	{
		width -= data->format.precision_value;
		if (width < 0)
			width = 0;
	}
	if (data->format.space)
		width -= 1;
	if (data->format.precision_value > 0)
		data->format.precision_value -= numlen(nbr);
	print_unint_strct(data, nbr, width);
}
