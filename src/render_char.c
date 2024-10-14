/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 02:57:05 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/14 14:21:33 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_printf_char(t_data *data, int c)
{
	int			width;

	if (data->format.zero == 1)
		data->format.zero = 0;
	width = data->format.width_value - 1;
	if (width < 0)
		width = 0;
	if (width > 0)
	{
		if (data->format.left_justified)
		{
			write_print(data, c);
			zero_space(data, width);
		}
		else
		{
			zero_space(data, width);
			write_print(data, c);
		}
	}
	else
		write_print(data, c);
}
