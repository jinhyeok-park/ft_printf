/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:46:36 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/04/05 19:03:39 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_null(const char *s)
{
	if (!*s)
	{
		write (1, "(null)", 6);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	size_t	i;
	va_list	ap;
	char	*buf;

	i = 0;
	buf = 0;

	if (ft_null(s))
		return (0);
	while (s[i])
	{
		if (s[i] == '%')
		{
			va_start(ap, s);
			buf = groupby_buf(buf, ap, s + i + 1);
			i++;
		}
		else
			buf = fill_buff_c(buf, s[i]);
		i++;
	}
	va_end(ap);
	i = ft_write(buf);
	if (i)
		free(buf);
	return (i);
}

int	ft_write(char *buf)
{
	size_t	i;

	i = 0;
	if (!buf)
		return (-1);
	while (buf[i])
		i++;
	write(1, buf, i);
	return (i);
}

char	*groupby_buf(char *buf, va_list ap, const char *s)
{
	char	*result;

	if (*s == 'c')
		result = fill_buff_c(buf, va_arg(ap, int));
	else if (*s == '%')
		result = fill_buff_c(buf, '%');
	else if (*s == 's')
		result = fill_buff_s(buf, va_arg(ap, char *));
	else if (*s == 'i' || *s == 'd')
	{
		result = ft_itoa((int)va_arg(ap, int));
		result = fill_buff_s(buf, result);
	}
	else
		result = buff_puxx(buf, ap, s);
	return (result);
}

char	*buff_puxx(char *buf, va_list ap, const char *s)
{
	char			*result;

	result = 0;
	if (*s == 'u')
		result = buff_u(buf, ap);
	else if (*s == 'p')
		result = buff_p(buf, ap);
	else if (*s == 'x')
		result = buff_xx(buf, ap, 0);
	else
		result = buff_xx(buf, ap, 1);
	return (result);
}
