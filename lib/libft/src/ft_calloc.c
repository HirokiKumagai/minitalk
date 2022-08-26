/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:40:09 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 05:06:32 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (SIZE_MAX / size < count)
	{
		errno = ENOMEM;
		return (NULL);
	}
	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}

//  #include <stdio.h>
// int	main()
// {
// 	printf("--------------test-----------------\n");
// 	int* calloc_test = (int *)calloc(10, sizeof(int));
// 	*calloc_test = 12;
// 	int *ft_calloc_test = (int *)ft_calloc(10, sizeof(int));
// 	*ft_calloc_test = 12;
// 	printf("original	%d\n", *calloc_test);
// 	printf("ft_function	%d\n", *ft_calloc_test);
// 	free(calloc_test);
// 	free(ft_calloc_test);

// 	char *calloc_test2 = (char *)calloc(10, sizeof(char));
// 	ft_strlcpy(calloc_test2, "test", ft_strlen("test") + 1);
// 	char *ft_calloc_test2 = (char *)ft_calloc(10, sizeof(char));
// 	ft_strlcpy(ft_calloc_test2, "test", ft_strlen("test") + 1);
// 	printf("original	%s\n", calloc_test2);
// 	printf("ft_function	%s\n", ft_calloc_test2);
// 	int i = 0;
// 	printf("calloc test\n");
// 	while (i < 10)
// 	{
// 		printf("%c\n", calloc_test2[i++]);
// 	}
// 	i = 0;
// 	printf("ft_calloc test\n");
// 	while (i < 10)
// 	{
// 		printf("%c\n", ft_calloc_test2[i++]);
// 	}
// 	free(calloc_test2);
// 	free(ft_calloc_test2);
// 	return (0);
// }
