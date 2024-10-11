/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:27:07 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/11 20:31:37 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	str_null(t_data *data)
{
	char	*str;

	str = "(null)";
	string_print(data, str);
	return ;
}

void	struct_str(t_data *data, const char *str, int width)
{
	if (width > 0)
	{
		if (data->format.left_justified)
		{
			string_print(data, str);
			zero_space(data, width);
		}
		else
		{
			zero_space(data, width);
			string_print(data, str);
		}
	}
	else
		string_print(data, str);
}

void	print_str(t_data *data, const char *str)
{
	int	width;

	width = data->format.width_value;
	if (width == 0 && str && str[0] == '\0')
		return ;
	if (!str)
		str = "(null)";
	if (data->format.precision_value != -1
		&& data->format.precision_value > width && width != 0)
	{
		width = 0;
	}
	else if (data->format.precision_value != -1
		&& data->format.precision_value < width && width != 0)
	{
		if (data->format.precision_value < (int)ft_strlen(str))
			width = data->format.width_value - data->format.precision_value;
		else
			width = data->format.width_value - (int)ft_strlen(str);
	}
	else
		width = data->format.width_value - (int)ft_strlen(str);
	struct_str(data, str, width);
}
