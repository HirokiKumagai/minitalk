/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:41:15 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 05:10:10 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	dest_length;
	size_t	src_length;

	count = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	dest_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (dstsize <= dest_length)
		return (dstsize + src_length);
	while (src[count] && dest_length + count < dstsize - 1)
	{
		dst[count + dest_length] = src[count];
		count++;
	}
	dst[count + dest_length] = '\0';
	return (dest_length + src_length);
}
