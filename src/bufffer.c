/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bufffer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 02:46:15 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/10 03:06:59 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	write_buf(t_data *data, char c)
{
	if (data->buffer_index == BUF_SIZE)
	{
		flush_buf()
	}
}
