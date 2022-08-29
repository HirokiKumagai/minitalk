/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 02:47:21 by hkumagai          #+#    #+#             */
/*   Updated: 2022/07/13 07:42:52 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_output_u(va_list args)
{
	int		nb;
	char	*res;
	size_t	len;

	nb = va_arg(args, unsigned int);
	res = ft_convert_from_base(10, nb, true);
	if (res == NULL)
		return (false);
	ft_putstr_fd(res, 1);
	len = strlen(res);
	free(res);
	return (len);
}
