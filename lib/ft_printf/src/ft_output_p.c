/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 04:53:52 by hkumagai          #+#    #+#             */
/*   Updated: 2022/07/13 07:42:39 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_output_p(va_list args)
{
	unsigned long long	nb;
	unsigned int		base;
	char				*res;
	size_t				len;

	base = 16;
	nb = (unsigned long long)va_arg(args, void *);
	res = ft_convert_from_base(base, nb, true);
	if (res == NULL)
		return (false);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(res, 1);
	len = strlen(res) + 2;
	free(res);
	return (len);
}
