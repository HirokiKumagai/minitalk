/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 03:49:36 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 05:11:27 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	ft_strnlen(char const *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strnlen(s, start);
	if (slen < start)
		slen = 0;
	else
		slen = ft_strnlen(&s[start], len);
	dst = (char *)malloc(sizeof(char) * (slen + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while ((i < slen) && (s[start + i] != '\0'))
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

// #include <ctype.h>
// #include <stdio.h>
// int main(){
// 	printf("-------------------test------------------\n");
// 	char test1[]= "test";
// 	unsigned int start = 1;
// 	size_t len = 3;
// 	char *dst1 = ft_substr(test1, start, len);

// 	printf("case:\t\tstart = 1, len = 3, start + len = 文字数\n");
// 	printf("ft_function:	%s\n", dst1);
// 	free(dst1);

// 	char test2[] = "test";
// 	start = 6;
// 	len = 10;

// 	char *dst2 = ft_substr(test2, start, len);
// 	printf("case:\t\tstart = 1, len = 10 ,start > 文字数\n");
// 	printf("ft_function:	%s\n", dst2);
// 	free(dst2);

// 	char test3[] = "test";
// 	start = 0;
// 	len = 10;

// 	char *dst3 = ft_substr(test3, start, len);
// 	printf("case:\t\tstart = 0, len = 10 (start < 文字数, len > 文字数)\n");
// 	printf("ft_function:	%s\n", dst3);
// 	free(dst3);

// 	char test4[] = "test";
// 	start = 3;
// 	len = 3;

// 	char *dst4 = ft_substr(test4, start, len);
// 	printf("case:\t\tstart = 3, len = 3 start + len > 文字数\n");
// 	printf("ft_function:	%s\n", dst4);
// 	free(dst4);

// 	char test5[] = "test";
// 	start = 6;
// 	len = 6;

// 	char *dst5 = ft_substr(test5, start, len);
// 	printf("case:\t\tstart = 6, len = 6 start + len > 文字数)\n");
// 	printf("ft_function:	%s\n", dst5);
// 	free(dst5);

// 	char test6[] = "test";
// 	start = 1;
// 	len = 0;

// 	char *dst6 = ft_substr(test6, start, len);
// 	printf("case:\t\tstart = 1, len = 0 start + len > 文字数\n");
// 	printf("ft_function:	%s\n", dst6);
// 	printf("ft_function(ヌル文字を確認):	0x%x\n", dst6[0]);
// 	free(dst6);
// 	return (0);
// }
