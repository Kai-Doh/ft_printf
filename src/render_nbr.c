/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:32:19 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/10 18:06:45 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	sign_space(t_data *data, int nbr)
{
	if (nbr > 0 && data->format.plus && data->format.space)
		write_print(data, '+');
	else if (nbr > 0 && data->format.plus)
		write_print(data, '+');
	else if (!data->format.plus && data->format.space)
		write_print(data, ' ');
}

void	print_nbr(t_data *data, int nbr)
{
	char	*num;

	num = ft_itoa(nbr);
	if (!num)
		return ;
	while (*num)
	{
		write_print(data, *num);
		num++;
	}
}

void	ft_printf_d(t_data *data, int nbr)
{
	int		width;

	width = data->format.width_value - numlen(nbr);
	if (width > 0)
	{
		if (!data->format.left_justified)
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
