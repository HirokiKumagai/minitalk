/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 07:10:33 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 05:08:50 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}
// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	int fd = open("putstr_file", O_RDWR | O_CREAT, S_IREAD | S_IWRITE);
// 	printf("%i\n", fd);
// 	if (fd == -1)
// 	{
// 		perror("error!");
// 		exit(EXIT_FAILURE);
// 	}
// 	char test[] = "testsample";
// 	ft_putstr_fd(test, fd);
// 	close(fd);
// 	exit(EXIT_SUCCESS);
// }
