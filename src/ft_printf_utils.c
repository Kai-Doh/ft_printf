/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:04:09 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/09 16:25:41 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	printchar(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	printstr(char *str)
{
	int	len;

	if (!str)
		str = "(null)";
	len = 0;
	while (str[len])
		len++;
	if (write(1, str, len) == -1)
		return (-1);
	return (len);
}
/*
return 6 on "(null)" because it takes 6 characters to print.
*/

int	printnbr(int n)
{
	int		len;
	char	*num;

	num = ft_itoa(n);
	if (!num)
		return (-1);
	len = printstr(num);
	free(num);
	return (len);
}

int	printpercent(void)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}
