/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:40:49 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 05:07:58 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*ch;

	if (!dst && !src)
		return (NULL);
	tmp = (unsigned char *)dst;
	ch = (unsigned char *)src;
	while (n--)
		*tmp++ = *ch++;
	return (dst);
}
