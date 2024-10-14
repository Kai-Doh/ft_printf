/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_str2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:55:47 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/14 17:19:11 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	zero_space_null(t_data *data, int size)
{
	char	*str;
	int		precision;

	precision = data->format.precision_value;
	str = "(null)";
	if (data->format.precision_value >= 0 && data->format.precision_value < 6)
		size -= data->format.precision_value;
	else
		size -= (int)ft_strlen(str);
	while (size > 0)
	{
		if (data->format.zero != 0)
			write_print(data, '0');
		else
			write_print(data, ' ');
		size--;
	}
	return ;
}

void	struct_str_null(t_data *data)
{
	if (data->format.precision_value == -1 && data->format.width_value == 0)
		str_null(data);
	else if (data->format.left_justified)
	{
		str_null(data);
		zero_space_null(data, data->format.width_value);
	}
	else
	{
		zero_space_null(data, data->format.width_value);
		str_null(data);
	}
}

void	struct_str_empty(t_data *data)
{
	if (data->format.width_value > 0)
	{
		if (data->format.left_justified)
		{
			zero_space(data, data->format.width_value);
		}
		else
		{
			zero_space(data, data->format.width_value);
		}
	}
	else
		return ;
}
