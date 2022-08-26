/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:41:18 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 05:10:18 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	src_length;

	count = 0;
	src_length = ft_strlen(src);
	while ((count + 1 < dstsize) && src[count])
	{
		dst[count] = src[count];
		count++;
	}
	if (0 < dstsize)
		dst[count] = '\0';
	return (src_length);
}

// #include <stdio.h>
// int main()
// {
// 	char dst1[] = "dst_sample";
// 	char src1[] = "hkumagai";

// 	ft_strlcpy(dst1, src1, 10);
// 	printf("通常: \t\t\t%s\n", dst1);

// 	char dst2[] = "dst_sample";
// 	char src2[] = "";

// 	ft_strlcpy(dst1, src1, 10);
// 	printf("srcがヌル文字:\t\t%s\n", dst1);

// 	char dst3[] = "dst_sample";
// 	char src3[] = "";

// 	ft_strlcpy(dst3, src3, 1);
// 	printf("srcがヌル文字かつ1文字:\t\t%s\n", dst3);
// }
