/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:55:58 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/04/05 19:40:07 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*buff_u(char *buf, va_list ap)
{
	char			*result;
	unsigned int	temp;

	temp = va_arg(ap, unsigned int);
	result = ft_itoa_longlong(temp);
	if (!buf)
	{
		result = buff_empty(0, result);
		return (result);
	}
	result = fill_buff_s(buf, result);
	return (result);
}

char	*buff_empty(unsigned char c, char *s)
{
	char	*result;

	result = NULL;
	if (c)
	{
		result = (char *)malloc(2);
		if (!result)
			return (0);
		result[0] = c;
		result[1] = 0;
		return (result);
	}
	if (s)
		result = ft_strdup(s);
	return (result);
}

void	fill_buff_c(char *s)
{
	write(1, s, 1);
}

char	*fill_buff_s(char *buf, char *s)
{
	char	*result;

	result = 0;
	if (!buf)
		result = buff_empty(0, s);
	else
	{
		result = ft_strjoin(buf, s);
		free(buf);
	}
	return (result);
}
