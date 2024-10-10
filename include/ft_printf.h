/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:03:09 by ktiomico          #+#    #+#             */
/*   Updated: 2024/10/10 02:35:10 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

#define BUF_SIZE	4096
#define FLAGS		"+ 0-#"
#define NUMBERS		"0123456789"
#define TYPE		"cspdiuxX%"

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
	e_base	base;
	int		upper_case;
}	t_format;

typedef enum
{
	OK = 0,
	MALLOC_ERROR = -1337,
	PARSE_ERROR = -42,
}	e_error;

typedef enum
{
	BASE_10 = 10,
	BASE_16 = 16,
}	e_base;

typedef struct	s_data
{
	const char	*s;
	va_list		ap;
	int			chars_written;
	char		*buf;
	int			buffer_index;
	t_format	format;
}	t_data;

int	check(const char *s, char c);
int	format_parsing(t_data *data);

#endif
