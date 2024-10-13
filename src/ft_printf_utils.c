/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 02:08:47 by ktiomico          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/11 12:54:03 by ktiomico         ###   ########.fr       */
=======
/*   Updated: 2024/10/13 14:57:34 by ktiomico         ###   ########.fr       */
>>>>>>> origin/bonus
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	check(const char *s, char c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int	write_print(t_data *data, int c)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	data->chars_written++;
	return (1);
}

int	string_print(t_data *data, const char *str)
{
	int	i;

	i = 0;
	if (data->format.precision_value == 0)
		return (0);
	else if (data->format.precision_value > 0)
	{
		while (i++ < data->format.precision_value && *str)
		{
			write_print(data, *str);
			str++;
			if (!*str)
				return (0);
		}
	}
	else if (data->format.precision_value == -1)
	{
		while (*str)
		{
			if (write_print(data, *str) == -1)
				return (-1);
			str++;
		}
	}
	return (0);
}

void	fill_space(t_data *data, const char c, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (write_print(data, c) == -1)
			return ;
		i++;
	}
}
