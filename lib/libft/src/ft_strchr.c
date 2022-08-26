/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:41:08 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 05:09:29 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *src, int c)
{
	while (*src != '\0' && *src != (char)c)
		src++;
	if (*src == (char)c)
		return ((char *)src);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main(){
// 	printf("-------------------test------------------\n");
// 	printf("original:	%s\n", strchr("test", 'e'));
// 	printf("ft_function:	%s\n", ft_strchr("test", 'e'));
// 	printf("original:	%p\n", strchr("test", 'a'));
// 	printf("ft_function:	%p\n", ft_strchr("test", 'a'));
// 	// NULLが渡されるとセグフォ
// 	// printf("original:	%p\n", strchr(NULL, 'a'));
// 	// printf("ft_function:	%p\n", ft_strchr(NULL, 'a'));
// 	return (0);
// }
