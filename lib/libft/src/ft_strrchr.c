/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:41:29 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 05:11:01 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (src[i] == (char)c)
			return ((char *)(src + i));
		i--;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main(){
// 	printf("-------------------test------------------\n");
// 	char test[] = "hiroki";
// 	printf("original:	%s\n", strrchr(test, 'i'));
// 	printf("ft_function:	%s\n", ft_strrchr(test, 'i'));
// 	char test2[] = "testtest";
// 	printf("original:	%p\n", strrchr(test2, '\0'));
// 	printf("ft_function:	%p\n", ft_strrchr(test2, '\0'));
// 	printf("original:	%p\n", strrchr(test2, 'a'));
// 	printf("ft_function:	%p\n", ft_strrchr(test2, 'a'));
// 	return (0);
// }
