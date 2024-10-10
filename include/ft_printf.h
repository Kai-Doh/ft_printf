/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:03:09 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/10 18:00:58 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

#define FLAGS		"+ 0-#"
#define NUMBERS		"0123456789"
#define TYPE		"cspdiuxX%"
#define OK	0
#define MALLOC -1337
#define PARSE_ERROR -42
#define BASE_10 10
#define BASE_16 16

typedef struct s_format
{
	int		left_justified;
	int		plus;
	int 	space;
	int		hashtag;
	int		zero;
	char	specifier;
	int		width_value;
	int		precision_value;
	int		upper_case;
	int		base;
}	t_format;

typedef struct	s_data
{
	va_list		ap;
	int			chars_written;
	t_format	format;
}	t_data;

int		check(const char *s, char c);
int		format_parsing(t_data *data, const char **format);
void	print_char(t_data *data, int c);
int		ft_printf(const char *format, ...);
int		write_print(t_data *data, int c);
void	print_str(t_data *data, const char *str);
int	string_print(t_data *data, const char *str);
void	zero_space(t_data *data, int size);
void	str_null(t_data *data);
void	ft_printf_d(t_data *data, int nbr);
int	numlen(long long nbr);

#endif
