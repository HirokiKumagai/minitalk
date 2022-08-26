/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:41:35 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 05:11:32 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c - ('A' - 'a'));
	return (c);
}

// #include <ctype.h>
// #include <stdio.h>
// #include <ctype.h>
// #include <stdio.h>
// int main(){
// 	printf("-------------------test------------------\n");
// 	printf("original:	%c\n", tolower('A'));
// 	printf("ft_function:	%c\n", ft_tolower('A'));
// 	printf("original:	%c\n", tolower('5'));
// 	printf("ft_function:	%c\n", ft_tolower('5'));
// 	printf("original:	%c\n", tolower('a'));
// 	printf("ft_function:	%c\n", ft_tolower('a'));
// 	return (0);
// }
