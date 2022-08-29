/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 04:43:00 by hkumagai          #+#    #+#             */
/*   Updated: 2022/07/13 07:42:31 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_output_c(va_list args)
{
	int		count;
	char	c;

	count = 0;
	c = va_arg(args, int);
	ft_putchar_fd(c, 1);
	count ++;
	return (count);
}
