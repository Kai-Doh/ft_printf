/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:03:09 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/09 23:27:25 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_flags
{
	int		left;
	int		zero;
	int		width;
	int		precision;
	int		star;
}	t_flags;

int		ft_printf(const char *type, ...);
int		printstr(char *str);
int		printnbr(int n);
int		printpercent(void);
int		printchar(int c);
int		format(char type, va_list args);
int		ft_ptr_len(unsigned long long address);
int		ft_put_hex(unsigned long long nbr);
int		ft_printf_ptr(unsigned long long address);
int		ft_printf_hex(unsigned int n);
int		ft_printf_hexupper(unsigned int n);
int		ft_put_hexupper(unsigned long long nbr);
int		ft_printf_unint(unsigned int n);
int		ft_nbr_len(unsigned int n);
int		ft_putunintnbr(unsigned int n);

#endif
