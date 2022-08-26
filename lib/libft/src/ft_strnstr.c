/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:41:27 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 05:10:51 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	i = 0;
	while (i < len && haystack[i])
	{
		j = 0;
		while (i + j < len && haystack[i + j] == needle[j])
		{
			j++;
			if (!needle[j])
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	printf("-------------------test------------------\n");
// 	// printf("original:	%p\n", strnstr("test", "test", 4));
// 	printf("ft_function:	%p\n", ft_strnstr("test", "test", 4));
// 	// printf("original:	%s\n", strnstr("test", "a", 4));
// 	printf("ft_function:	%s\n", ft_strnstr("test", "a", 4));
// 	// printf("original:	%s\n", strnstr("apple", "banana", 4));
// 	printf("ft_function:	%s\n", ft_strnstr("apple", "banana", 4));
// 	// printf("original:	%p\n", strnstr("", "a", 4));
// 	printf("ft_function:	%p\n", ft_strnstr("", "a", 4));
// 	// printf("original:	%s\n", strnstr("test", "", 4));
// 	printf("ft_function:	%s\n", ft_strnstr("test", "", 4));
// 	// printf("original:	%s\n", strnstr("testsample", "test", 0));
// 	printf("ft_function:	%s\n", ft_strnstr("testsample", "test", 0));
// 	// printf("original:	%s\n", strnstr(NULL, "test", 0));
// 	printf("ft_function:	%s\n", ft_strnstr(NULL, "test", 0));
// 	return (0);
// }
