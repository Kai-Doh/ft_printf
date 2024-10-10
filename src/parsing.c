/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:56:18 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/10 02:34:42 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

static int	pf_atoi(t_data *data)
{
	int	value;

	value = 0;
	while (check(NUMBERS, *data->s))
		value = (value * 10) + (*data->s++ - '0');
	return (value);
}
static void parse_flags(t_data *data)
{
	char	flag;

	while (check(FLAGS, *data->s))
	{
		flag = *data->s;
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
		data->s++;
	}
}

static void	parse_width(t_data *data)
{

}

static void	get_value(t_data *data, int *value)
{
	if (*data->s == '*')
	{
		*value = va_arg(data->ap, int);
		data->s++;
		return ;
	}
	*value = ft_atoi(data)
}

int	format_parsing(t_data *data)
{
	ft_memset(&data->format, 0, sizeof(t_format));
	data->format.precision_value = -1;
	parse_flags(data);
	get_value(data, &data->format.width_value)
	if (*data->s == '.' && (++data.s))
		get_value(data, &data->format.precision_value);
	if (!check(TYPE, *data.s))
		return (PARSE_ERROR);
	else
	{
		data->format.specifier = *data->s;
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
