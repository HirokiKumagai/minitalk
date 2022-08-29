/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_xX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 04:22:22 by hkumagai          #+#    #+#             */
/*   Updated: 2022/07/13 07:42:57 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_output_x(va_list args)
{
	long long int	nb;
	unsigned int	base;
	char			*res;
	size_t			len;

	base = 16;
	nb = va_arg(args, long long int);
	res = ft_convert_from_base(base, nb, true);
	if (res == NULL)
		return (false);
	ft_putstr_fd(res, 1);
	len = strlen(res);
	free(res);
	return (len);
}

int	ft_output_X(va_list args)
{
	long long int	nb;
	unsigned int	base;
	char			*res;
	size_t			len;
	int				i;

	base = 16;
	nb = va_arg(args, long long int);
	res = ft_convert_from_base(base, nb, true);
	if (res == NULL)
		return (false);
	i = 0;
	while (res[i])
	{
		res[i] = ft_toupper(res[i]);
		i++;
	}
	ft_putstr_fd(res, 1);
	len = strlen(res);
	free(res);
	return (len);
}
