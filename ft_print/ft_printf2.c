/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:51:24 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/04/05 16:25:14 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*buff_xx(char *buf, va_list ap, int u_sign)
{
	char		*result;
	long long	temp;

	result = 0;
	temp = (long long)va_arg(ap, int);
	if (u_sign)
		result = ft_tohex(temp, 1);
	else
		result = ft_tohex(temp, 0);
	if (!buf)
	{
		result = buff_empty(0, result);
		return (result);
	}
	result = fill_buff_s(buf, result);
	free(buf);
	return (result);
}

char	*buff_p(char *buf, va_list ap)
{
	char		*result;
	char		*p;
	long long	temp;

	p = "0x";
	temp = (long long)va_arg(ap, void *);
	result = ft_tohex(temp, 0);
	result = ft_strjoin(p, result);
	if (!buf)
	{
		result = buff_empty(0, result);
		return (result);
	}
	result = fill_buff_s(buf, result);
	return (result);
}

char	*ft_tohex(long long num, int u_sign)
{
	long long	temp;
	size_t		i;
	int			sign;

	temp = num;
	sign = 1;
	i = 0;
	if (temp < 0)
	{
		sign = -1;
		temp *= -1;
		num *= -1;
	}
	while (temp)
	{
		i++;
		temp /= 16;
	}
	temp = num;
	return (ft_tohex2(sign, temp, i, u_sign));
}

char	*ft_tohex2(int sign, long long temp, size_t i, int u_sign)
{
	char	*result;

	if (sign < 0)
		i++;
	result = (char *)malloc(i + 1);
	if (!result)
		return (0);
	result[i] = 0;
	if (sign < 0)
		result[--i] = '-';
	while (temp)
	{
		if (u_sign)
			result[--i] = "0123456789ABCDEF"[temp % 16];
		else
			result[--i] = "0123456789abcdef"[temp % 16];
		temp /= 16;
	}
	return (result);
}

char	*ft_itoa_longlong(long long num)
{
	size_t		len;
	char		*result;
	long long	temp;

	temp = num;
	len = 0;
	while (temp)
	{
		temp /= 10;
		len ++;
	}
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	result[len] = 0;
	temp = num;
	while (temp)
	{
		result[--len] = "0123456789"[temp % 10];
		temp /= 10;
	}
	return (result);
}
