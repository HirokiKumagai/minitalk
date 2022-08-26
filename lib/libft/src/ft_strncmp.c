/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:41:24 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 05:10:43 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == '\0' && s1[i] == s2[i])
			return (0);
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else
			i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main(){
// 	printf("-------------------test------------------\n");
// 	char dest[] = "test";
// 	char src[] = "test";
// 	printf("original:	%d\n", strncmp(dest, src, 4));
// 	printf("ft_function:	%d\n", ft_strncmp(dest, src, 4));
// 	char dest2[] = "test1";
// 	char src2[] = "test2";
// 	printf("original:	%d\n", strncmp(dest2, src2, 5));
// 	printf("ft_function:	%d\n", ft_strncmp(dest2, src2, 5));
// 	char dest3[] = "test3";
// 	char src3[] = "test2";
// 	printf("original:	%d\n", strncmp(dest3, src3, 8));
// 	printf("ft_function:	%d\n", ft_strncmp(dest3, src3, 8));

// 	// セグフォになる
// 	// printf("original:	%d\n", strncmp(NULL, src3, 5));
// 	// printf("ft_function:	%d\n", ft_strncmp(NULL, src3, 5));
// 	// printf("original:	%d\n", strncmp(dest3, NULL, 5));
// 	// printf("ft_function:	%d\n", ft_strncmp(dest3, NULL, 5));
// 	// printf("original:	%d\n", strncmp(NULL, NULL, 5));
// 	// printf("ft_function:	%d\n", ft_strncmp(NULL, NULL, 5));
// 	return 0;
// }
