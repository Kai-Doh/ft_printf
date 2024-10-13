/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:27:07 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/13 19:33:18 by ktiomico         ###   ########.fr       */
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
			if ((!str && width > 6) || str)
				zero_space(data, width);
		}
		else
		{
			if ((!str && width > 6) || str)
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
	int	str_len;

	if (!str)
		str = "(null)";
	if (data->format.precision_value != -1)
	{
		if (data->format.precision_value == 0)
			str_len = 0;
		else if (data->format.precision_value < (int)ft_strlen(str))
			str_len = data->format.precision_value;
		else if (str)
			str_len = (int)ft_strlen(str);
		else if (!str)
			str_len = 6;
	}
	else
	{
		str_len = (int)ft_strlen(str);
	}
	width = data->format.width_value - str_len;
	if (width < 0)
		width = 0;
	struct_str(data, str, width);
}
