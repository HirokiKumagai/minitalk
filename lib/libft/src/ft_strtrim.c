/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:41:31 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 05:11:13 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;
	size_t	i;

	if (str == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (str[start] != '\0' && ft_strchr(set, str[start]))
		start++;
	end = ft_strlen(str);
	while (end > start && ft_strchr(set, str[end - 1]))
		end--;
	trim = (char *)malloc(sizeof(char) * (end - start + 1));
	if (trim == NULL)
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		trim[i] = str[start + i];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}
// #include <ctype.h>
// #include <stdio.h>
// int main()
// {
// 	printf("-------------------test------------------\n");
// 	char test1[] = "test";
// 	char test2[] = "t";
// 	char *dst1 = ft_strtrim(test1, test2);
// 	printf("case:\t\ttestからtを抜く\n");
// 	printf("ft_function:	%s\n", dst1);
// 	free(dst1);

// 	char test3[] = "teseessset";
// 	char test4[] = "te";
// 	char *dst2 = ft_strtrim(test3, test4);
// 	printf("case:\t\ttestからteを抜く\n");
// 	printf("ft_function:	%s\n", dst2);
// 	free(dst2);
// 	return (0);
// }
