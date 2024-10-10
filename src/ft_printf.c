/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:18:46 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/10 01:55:31 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	init_data(t_data *data, const char *format)
{
	data->chars_written = 0;
	data->s = format;
	data->buf = ft_calloc(BUF_SIZE, sizeof(char));
	if (data->buf == NULL)
		return (MALLOC_ERROR);
	data->buffer_index = 0;
	return (OK);
}
int	ft_printf(const char *format, ...)
{
	t_data	data;

	va_start(data.ap, format);
	if (init_data(&data, format))
		return (-1);
	while (*data.s)
	{
		if (*data.s == '%' && *(++data.s))
		{
			if (parse_format(&data))
			{
				return (PARSE_ERROR);
			}
			render_format(&data);
		}
		else
		{
			write_buf(&data, *data.s);
		}
		++data.s;
	}
	flush_buf(&data);
	va_end(data.ap);
	free(data.buf);
	return (data.chars_written);
}
