/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:32:19 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/11 15:16:17 by ktiomico         ###   ########.fr       */
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

void	print_nbr(t_data *data, long long nbr)
{
	char	*num;
	char	*tmp;

	if (nbr < 0)
		nbr *= -1;
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

void	print_nbr_strct(t_data *data, long long nbr, int width)
{
	if (width > 0)
	{
		if (data->format.left_justified)
		{
			sign_space(data, nbr);
			print_prec_zero(data);
			print_nbr(data, nbr);
			zero_space(data, width);
		}
		else
		{
			sign_space(data, nbr);
			zero_space(data, width);
			print_prec_zero(data);
			print_nbr(data, nbr);
		}
	}
	else
	{
		sign_space(data, nbr);
		print_prec_zero(data);
		print_nbr(data, nbr);
	}
}

void	ft_printf_int(t_data *data, int nbr)
{
	int		width;

	width = data->format.width_value - numlen(nbr);
	if (data->format.precision_value != -1)
	{
		width -= data->format.precision_value;
		if (width < 0)
			width = 0;
	}
	if (data->format.plus == 1 || (data->format.space && nbr > -1))
		width -= 1;
	if (data->format.precision_value > 0 && (nbr < 0 || data->format.plus == 1))
		data->format.precision_value -= numlen(nbr) - 1;
	else if (data->format.precision_value > 0 && nbr >= 0)
		data->format.precision_value -= numlen(nbr);
	print_nbr_strct(data, nbr, width);
}
