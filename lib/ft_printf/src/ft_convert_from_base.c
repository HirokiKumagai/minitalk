/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_from_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 08:17:07 by hkumagai          #+#    #+#             */
/*   Updated: 2022/07/13 07:42:20 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	ft_nblen(int base, unsigned long long nb, \
unsigned long long *exp, bool sign)
{
	size_t				len;

	len = 1;
	if (!sign)
		len++;
	while (*exp <= nb / base)
	{
		*exp *= base;
		len++;
	}
	return (len);
}

char	*ft_convert_from_base(int base, unsigned long long nb, bool sign)
{
	unsigned long long	exp;
	size_t				len;
	char				*tmp;
	int					i;

	exp = 1;
	len = ft_nblen(base, nb, &exp, sign);
	tmp = (char *)malloc(sizeof(char) * len + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	if (!sign)
		tmp[i++] = '-';
	while (exp > 0)
	{
		tmp[i++] = "0123456789abcdef"[(nb / exp) % base];
		exp /= base;
	}
	tmp[i] = '\0';
	return (tmp);
}
