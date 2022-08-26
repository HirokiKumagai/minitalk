/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:41:38 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 05:11:38 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c + ('A' - 'a'));
	return (c);
}

// #include <ctype.h>
// #include <stdio.h>
// int main()
// {
// 	printf("-------------------test------------------\n");
// 	printf("original:	%c\n", toupper('A'));
// 	printf("ft_function:	%c\n", ft_toupper('A'));
// 	printf("original:	%c\n", toupper('5'));
// 	printf("ft_function:	%c\n", ft_toupper('5'));
// 	printf("original:	%c\n", toupper('a'));
// 	printf("ft_function:	%c\n", ft_toupper('a'));
// 	return (0);
// }
