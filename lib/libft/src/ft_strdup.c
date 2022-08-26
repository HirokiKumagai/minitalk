/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:41:10 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 05:09:39 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	i;

	p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

// #include <stdio.h>
// #include <string.h>
// int main(){
// 	printf("-------------------strdup------------------\n");
// 	char *s1 = "testtest";
// 	char *s2;
// 	s2 = strdup(s1);
// 	printf("元の文字列\t\t\t:%s\n", s1);
// 	printf("コピーした文字列\t\t:%s\n", s2);
// 	printf("元の文字列のメモリ番地\t\t:%p\n", s1);
// 	printf("コピーした文字列のメモリ番地\t:%p\n", s2);
// 	free(s2);
// 	printf("-------------------ft_strdup------------------\n");
// 	char *s3 = "testtest";
// 	char *s4;
// 	s4 = ft_strdup(s3);
// 	printf("元の文字列\t\t\t:%s\n", s3);
// 	printf("コピーした文字列\t\t:%s\n", s4);
// 	printf("元の文字列のメモリ番地\t\t:%p\n", s3);
// 	printf("コピーした文字列のメモリ番地\t:%p\n", s4);
// 	free(s4);
// 	return (0);
// }
