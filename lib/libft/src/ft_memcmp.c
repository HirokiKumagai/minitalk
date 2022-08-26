/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:40:44 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 05:07:47 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	printf("-------------------test------------------\n");
// 	printf("original:	%d\n", memcmp("test", "test", 4));
// 	printf("ft_function:	%d\n", ft_memcmp("test", "test", 4));
// 	printf("original:	%d\n", memcmp("test", "a", 4));
// 	printf("ft_function:	%d\n", ft_memcmp("test", "a", 4));
// 	printf("original:	%d\n", memcmp("apple", "banana", 4));
// 	printf("ft_function:	%d\n", ft_memcmp("apple", "banana", 4));
// 	printf("original:	%d\n", memcmp("", "a", 4));
// 	printf("ft_function:	%d\n", ft_memcmp("", "a", 4));
// 	printf("original:	%d\n", memcmp("test", "", 4));
// 	printf("ft_function:	%d\n", ft_memcmp("test", "", 4));
// 	// NULLはセグフォになる
// 	// printf("original:	%p\n", memcmp(NULL, "a", 4));
// 	// printf("ft_function:	%p\n", ft_memcmp(NULL, "a", 4));
// 	// printf("original:	%p\n", memcmp("test", NULL, 4));
// 	// printf("ft_function:	%p\n", ft_memcmp("test", NULL, 4));
// 	printf("original:	%d\n", memcmp(NULL, NULL, 4));
// 	printf("ft_function:	%d\n", ft_memcmp(NULL, NULL, 4));
// 	return (0);
// }
