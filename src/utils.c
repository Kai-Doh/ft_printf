/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:04:09 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/08 17:26:03 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	printchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i);
}
/*
return 6 on "(null)" because it takes 6 characters to print.
*/

int	printnbr(int n)
{
	int		len;
	char	*num;

	num = ft_itoa(n);
	len = printstr(num);
	free(num);
	return (len);
}

int	printpercent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
