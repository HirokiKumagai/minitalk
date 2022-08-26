/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:39:57 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 05:13:39 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
// #include <stdio.h>
// #include <stdlib.h>

int	ft_atoi(const char *str)
{
	size_t	i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r' \
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

// int	main()
// {
// 	printf("--------------atoi-----------------\n");
// 	char test_case[] = "1234";
// 	printf("original	%d\n", atoi(test_case));
// 	printf("ft_function	%d\n", ft_atoi(test_case));
// 	char test_case2[] = "-12344";
// 	printf("original	%d\n", atoi(test_case2));
// 	printf("ft_function	%d\n", ft_atoi(test_case2));
// 	char test_case3[] = "--12344";
// 	printf("original	%d\n", atoi(test_case3));
// 	printf("ft_function	%d\n", ft_atoi(test_case3));
// 	char test_case4[] = "++12344";
// 	printf("original	%d\n", atoi(test_case4));
// 	printf("ft_function	%d\n", ft_atoi(test_case4));
// 	char test_case5[] = " 12344";
// 	printf("original	%d\n", atoi(test_case5));
// 	printf("ft_function	%d\n", ft_atoi(test_case5));
// 	char test_case6[] = " 	12344";
// 	printf("original	%d\n", atoi(test_case6));
// 	printf("ft_function	%d\n", ft_atoi(test_case6));
// 	char test_case7[] = " \f\n\v\r\t1234";
// 	printf("original	%d\n", atoi(test_case7));
// 	printf("ft_function	%d\n", ft_atoi(test_case7));
// 	char test_case8[] = "2147483647";
// 	printf("original	%d\n", atoi(test_case8));
// 	printf("ft_function	%d\n", ft_atoi(test_case8));
// 	char test_case9[] = "-2147483648";
// 	printf("original	%d\n", atoi(test_case9));
// 	printf("ft_function	%d\n", ft_atoi(test_case9));
// 	char test_case10[] = "2147483648";
// 	printf("original	%d\n", atoi(test_case10));
// 	printf("ft_function	%d\n", ft_atoi(test_case10));
// 	char test_case11[] = "-2147483649";
// 	printf("original	%d\n", atoi(test_case11));
// 	printf("ft_function	%d\n", ft_atoi(test_case11));
// 	char test_case12[] = "9223372036854775807";
// 	printf("original	%d\n", atoi(test_case12));
// 	printf("ft_function	%d\n", ft_atoi(test_case12));
// 	char test_case13[] = "-9223372036854775808";
// 	printf("original	%d\n", atoi(test_case13));
// 	printf("ft_function	%d\n", ft_atoi(test_case13));
// 	char test_case14[] = "9223372036854775808";
// 	printf("original	%d\n", atoi(test_case14));
// 	printf("ft_function	%d\n", ft_atoi(test_case14));
// 	char test_case15[] = "-9223372036854775809";
// 	printf("original	%d\n", atoi(test_case15));
// 	printf("ft_function	%d\n", ft_atoi(test_case15));
// 	return (0);
// }
