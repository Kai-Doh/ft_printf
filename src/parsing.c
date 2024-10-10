/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:56:18 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/10 15:45:49 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	pf_atoi(const char **format)
{
	int	value;

	value = 0;
	while (check(NUMBERS, **format))
		value = (value * 10) + (*(*format)++ - '0');
	return (value);
}
static void	parse_flags(t_data *data, const char **format)
{
	char	flag;

	while (check(FLAGS, **format))
	{
		flag = **format;
		if ('0' == flag)
			data->format.zero = 1;
		else if ('+' == flag)
			data->format.plus = 1;
		else if (' ' == flag)
			data->format.space = 1;
		else if ('#' == flag)
			data->format.hashtag = 1;
		else if ('-' == flag)
			data->format.left_justified = 1;
		(*format)++;
	}
}
/*
static void	parse_width(t_data *data)
{

}
*/
static void	get_value(t_data *data, int *value, const char **format)
{
	if (**format == '*')
	{
		*value = va_arg(data->ap, int);
		(*format)++;
		return ;
	}
	*value = pf_atoi(format);
}

int	format_parsing(t_data *data, const char **format)
{
	ft_memset(&data->format, 0, sizeof(t_format));
	data->format.precision_value = -1;
	parse_flags(data, format);
	get_value(data, &data->format.width_value, format);
	if (**format == '.' && ++(*format))
		get_value(data, &data->format.precision_value, format);
	if (!check(TYPE, **format))
		return (PARSE_ERROR);
	else
	{
		data->format.specifier = **format;
		if (check("diu", data->format.specifier))
			data->format.base = BASE_10;
		else if (check("xXp", data->format.specifier))
		{
			data->format.base = BASE_16;
			if ('X' == data->format.specifier)
				data->format.upper_case = 1;
		}
	}
	return (OK);
}
