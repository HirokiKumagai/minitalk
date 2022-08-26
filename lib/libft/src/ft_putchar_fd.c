/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 07:10:25 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 05:08:18 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	int fd = open("putchar_file", O_RDWR | O_CREAT, S_IREAD | S_IWRITE);
// 	int fd2 = open("putchar_file2", O_RDWR | O_CREAT, S_IREAD | S_IWRITE);
// 	printf("%i\n", fd);
// 	printf("%i\n", fd2);
// 	if (fd == -1)
// 	{
// 		perror("error!");
// 		exit(EXIT_FAILURE);
// 	}
// 	ft_putchar_fd('a', fd);
// 	ft_putchar_fd('a', fd2);
// 	close(fd);
// 	close(fd2);
// 	exit(EXIT_SUCCESS);
// }
