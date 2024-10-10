/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:32:19 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/11 00:02:15 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	numlen(long long nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_lolo_itoa(long long n)
{
	char			*str;
	int				len;
	unsigned int	nbr;

	len = numlen(n);
	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		str[0] = '-';
	while (len-- > (n < 0))
	{
		str[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}

void	sign_space(t_data *data, long long nbr)
{
	if (nbr > 0 && data->format.plus && data->format.space)
		write_print(data, '+');
	else if (nbr > 0 && data->format.plus)
		write_print(data, '+');
	else if (!data->format.plus && data->format.space)
		write_print(data, ' ');
}

void	print_nbr(t_data *data, long long nbr)
{
	char	*num;
	char	*tmp;

	num = ft_lolo_itoa(nbr);
	if (!num)
		return ;
	tmp = num;
	while (*num)
	{
		write_print(data, *num);
		num++;
	}
	free(tmp);
}

void	ft_printf_int(t_data *data, int nbr)
{
	int		width;

	width = data->format.width_value - numlen(nbr);
	if (width > 0)
	{
		if (data->format.left_justified)
		{
			sign_space(data, nbr);
			print_nbr(data, nbr);
			zero_space(data, width);
		}
		else
		{
			zero_space(data, width);
			sign_space(data, nbr);
			print_nbr(data, nbr);
		}
	}
	else
	{
		sign_space(data, nbr);
		print_nbr(data, nbr);
	}
}
