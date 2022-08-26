/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:40:31 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 05:07:40 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	printf("-------------------test------------------\n");
// 	printf("original:	%p\n", memchr("test", 'e', 4));
// 	printf("ft_function:	%p\n", ft_memchr("test", 'e', 4));
// 	printf("original:	%p\n", memchr("test", 'a', 4));
// 	printf("ft_function:	%p\n", ft_memchr("test", 'a', 4));
// 	printf("original:	%p\n", memchr("", 'a', 4));
// 	printf("ft_function:	%p\n", ft_memchr("", 'a', 4));
// 	// NULLはセグフォになる
// 	// printf("original:	%p\n", memchr(NULL, 'a', 4));
// 	// printf("ft_function:	%p\n", ft_memchr(NULL, 'a', 4));
// 	return (0);
// }
