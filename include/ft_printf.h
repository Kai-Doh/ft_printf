/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:00:00 by assistant         #+#    #+#             */
/*   Updated: 2024/10/10 00:17:13 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_format
{
	int		flags;
	int		width;
	int		precision;
	char	specifier;
}				t_format;

# define FLAG_MINUS	1
# define FLAG_ZERO	2
# define FLAG_HASH	4
# define FLAG_SPACE	8
# define FLAG_PLUS	16
# define FLAG_DOT	32

int		ft_printf(const char *fmt, ...);
int		ft_parse_format(const char **fmt, t_format *f, va_list ap);
int		ft_handle_conversion(t_format *f, va_list ap, int *len);
int		ft_putchar(char c);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *s);
char	*ft_itoa(long n);
char	*ft_uitoa_base(unsigned long n, int base, int uppercase);
int		ft_print_char(t_format *f, va_list ap, int *len);
int		ft_print_string(t_format *f, va_list ap, int *len);
int		ft_print_pointer(t_format *f, va_list ap, int *len);
int		ft_print_number(t_format *f, va_list ap, int *len);
int		ft_print_unsigned(t_format *f, va_list ap, int *len);
int		ft_print_hex(t_format *f, va_list ap, int uppercase, int *len);
int		ft_apply_width(char **str, t_format *f);
int		ft_apply_precision(char **str, t_format *f);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strdup(const char *s1);
void	ft_strtoupper(char *s);

#endif
