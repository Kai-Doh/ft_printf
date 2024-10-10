/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:27:07 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/10 18:15:24 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	print_str(t_data *data, const char *str)
{
	int	width;

	if (!str)
		str = "(null)";
	width = data->format.width_value - (int)ft_strlen(str);
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
