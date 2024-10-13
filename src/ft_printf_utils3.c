/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:48:37 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/13 17:48:45 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	print_nbr(t_data *data, long long nbr)
{
	if (nbr < 0)
		nbr *= -1;
	if (nbr >= 10)
	{
		print_nbr(data, nbr / 10);
		print_nbr(data, nbr % 10);
	}
	else
		write_print(data, nbr + '0');
}

int	numlen(long long nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

void	zero_space_sign(t_data *data, int size, int nbr)
{
	if (nbr < 0 && data->format.zero)
	{
		write_print(data, '-');
		fill_space(data, '0', size);
	}
	else
	{
		if (data->format.zero)
			fill_space(data, '0', size);
		else
			fill_space(data, ' ', size);
	}
	return ;
}
