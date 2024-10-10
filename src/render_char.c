/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 02:57:05 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/10 03:06:59 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

void	print_char(t_data *data, int c)
{
	int	width;

	width = data->format.width_value;
	if (width > 1)
	{
		if (data->format.left_justified)
		{
			putchar_buf_n((char)c, )
		}
		else
		{

		}

	}
}
