/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 08:29:28 by hkumagai          #+#    #+#             */
/*   Updated: 2022/07/13 07:44:52 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_output_di(va_list args)
{
	bool					sign;
	int						nb;
	unsigned long long int	unb;
	char					*res;
	size_t					len;

	sign = true;
	nb = va_arg(args, int);
	if (nb < 0)
	{
		sign = false;
		unb = -nb;
	}
	else
		unb = nb;
	res = ft_convert_from_base(10, unb, sign);
	if (res == NULL)
		return (false);
	ft_putstr_fd(res, 1);
	len = strlen(res);
	free(res);
	return (len);
}
