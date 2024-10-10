/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_unint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:39:33 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/11 00:02:54 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_printf_unint(t_data *data, unsigned int nbr)
{
	int		width;

	width = data->format.width_value - numlen(nbr);
	if (width > 0)
	{
		if (data->format.left_justified)
		{
			sign_space(data, nbr);
			print_nbr(data, nbr);
			zero_space(data, width);
		}
		else
		{
			zero_space(data, width);
			sign_space(data, nbr);
			print_nbr(data, nbr);
		}
	}
	else
	{
		sign_space(data, nbr);
		print_nbr(data, nbr);
	}
}
