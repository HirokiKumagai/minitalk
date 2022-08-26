/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:40:52 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 05:08:06 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*ch;

	if (!dest && !src)
		return (NULL);
	tmp = (unsigned char *)dest;
	ch = (unsigned char *)src;
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
		while (n--)
			*(tmp + n) = *(ch + n);
	return (dest);
}
