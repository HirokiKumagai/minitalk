/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:40:28 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 05:07:33 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	ft_count_len(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static unsigned int	ft_abs(int n)
{
	unsigned int	result;

	if (n < 0)
		result = -n;
	else
		result = n;
	return (result);
}

char	*ft_itoa(int n)
{
	char			*result;
	size_t			len;
	unsigned int	nb;

	len = ft_count_len(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	nb = ft_abs(n);
	result[len] = '\0';
	while (len > 0)
	{
		result[len - 1] = "0123456789"[nb % 10];
		nb /= 10;
		len--;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}

// #include <ctype.h>
// #include <stdio.h>
// int main()
// {
// 	char *test1 = ft_itoa(42);
// 	char *test2 = ft_itoa(-42);
// 	char *test3 = ft_itoa(INT_MAX);
// 	char *test4 = ft_itoa(INT_MIN);
// 	printf("-------------------test------------------\n");
// 	printf("42:\t\t%s\n", test1);
// 	printf("-42:\t\t%s\n", test2);
// 	printf("INT_MAX:\t%s\n", test3);
// 	printf("INT_MIN:\t%s\n", test4);

// 	free(test1);
// 	free(test2);
// 	free(test3);
// 	free(test4);

// 	return (0);
// }
