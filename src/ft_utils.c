/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:25:00 by assistant         #+#    #+#             */
/*   Updated: 2024/10/10 00:08:20 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;
	int	ret;

	len = 0;
	while (*s)
	{
		ret = ft_putchar(*s++);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	return (len);
}

size_t	ft_strlen(const char *s)
{
	size_t len = 0;

	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	s2 = (char *)malloc(len + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(len1 + len2 + 1);
	if (!str)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	i = -1;
	while (++i < len1)
		str[i] = s1[i];
	i = -1;
	while (++i < len2)
		str[len1 + i] = s2[i];
	str[len1 + len2] = '\0';
	free(s1);
	free(s2);
	return (str);
}
