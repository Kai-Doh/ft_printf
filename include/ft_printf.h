/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:03:09 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/13 23:27:23 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FLAGS		"+ 0-#"
# define NUMBERS		"0123456789"
# define TYPE		"cspdiuxX%"
# define OK	0
# define MALLOC -1337
# define PARSE_ERROR -42
# define BASE_10 10
# define BASE_16 16

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_format
{
	int		left_justified;
	int		plus;
	int		space;
	int		hashtag;
	int		zero;
	char	specifier;
	int		width_value;
	int		precision_value;
}	t_format;

typedef struct s_data
{
	va_list		ap;
	int			chars_written;
	t_format	format;
}	t_data;

int		check(const char *s, char c);
void	fill_space(t_data *data, const char c, int size);
int		ft_printf(const char *format, ...);
void	ft_printf_add(t_data *data, void *address);
void	ft_printf_char(t_data *data, int c);
void	ft_printf_hex(t_data *data, unsigned int nbr);
void	ft_printf_int(t_data *data, int nbr);
void	ft_printf_unint(t_data *data, unsigned int nbr);
int		format_parsing(t_data *data, const char **format);
int		hex_length(unsigned long long n);
int		numlen(long long nbr);
void	print_hex(t_data *data, unsigned long long nbr);
void	print_nbr(t_data *data, long long nbr);
void	print_prec_zero_d(t_data *data, int precision);
void	print_prec_zero(t_data *data);
void	print_str(t_data *data, const char *str);
void	struct_unint_zero(t_data *data, unsigned int nbr);
void	sign_space(t_data *data, long long nbr);
int		string_print(t_data *data, const char *str, int precision);
void	str_null(t_data *data);
int		write_print(t_data *data, int c);
void	zero_space(t_data *data, int size);
void	zero_space_sign(t_data *data, int size, int nbr);
void	struct_str_null(t_data *data);
void	struct_str_empty(t_data *data);

#endif
