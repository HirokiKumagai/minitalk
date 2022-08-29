/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 05:22:44 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/25 08:56:10 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_process(const char *format, va_list args, int count, int index)
{
	if (format[index] == 'c')
		count += ft_output_c(args);
	if (format[index] == 's')
		count += ft_output_s(args);
	if (format[index] == 'p')
		count += ft_output_p(args);
	if (format[index] == 'd' || format[index] == 'i')
		count += ft_output_di(args);
	if (format[index] == 'u')
		count += ft_output_u(args);
	if (format[index] == 'x')
		count += ft_output_x(args);
	if (format[index] == 'X')
		count += ft_output_X(args);
	if (format[index] == '%')
		count += ft_output_ps();
	return (count);
}

int	ft_formatlen(const char *format, va_list args)
{
	int		index;
	int		count;

	index = 0;
	count = 0;
	while (format[index])
	{
		if (format[index] == '%')
		{
			index++;
			count = ft_process(format, args, count, index);
			index++;
		}
		else
		{
			ft_putchar_fd(format[index], 1);
			count++;
			index++;
		}
	}
	return (count);
}
