/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 07:10:12 by hkumagai          #+#    #+#             */
/*   Updated: 2022/07/09 02:30:08 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	int fd = open("putendl_file", O_RDWR | O_CREAT, S_IREAD | S_IWRITE);
// 	printf("%i\n", fd);
// 	if (fd == -1)
// 	{
// 		perror("error!");
// 		exit(EXIT_FAILURE);
// 	}
// 	char test[] = "testsample";
// 	ft_putendl_fd(test, fd);
// 	close(fd);
// 	exit(EXIT_SUCCESS);
// }