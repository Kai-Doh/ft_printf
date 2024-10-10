/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 02:08:47 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/10 10:01:19 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check(const char *s, char c)
{
	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int	write_print(t_data *data, int c);
{
	if (write (1, *format, 1) == -1)
		return (-1);
	data->chars_written++;
	return (1);
}
