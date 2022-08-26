/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 07:10:30 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 05:08:43 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static unsigned int	ft_putneg_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		return (-n);
	}
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int		nb;
	unsigned int		exp;
	const unsigned int	base = 10;

	nb = ft_putneg_fd(n, fd);
	exp = 1;
	while (exp <= nb / base)
		exp *= base;
	while (exp > 0)
	{
		ft_putchar_fd("0123456789"[nb / exp % base], fd);
		exp /= base;
	}
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	int fd = open("putnbr_file", O_RDWR | O_CREAT, S_IREAD | S_IWRITE);
// 	printf("%i\n", fd);
// 	if (fd == -1)
// 	{
// 		perror("error!");
// 		exit(EXIT_FAILURE);
// 	}
// 	int	num = 1100213213;
// 	ft_putnbr_fd(num, fd);
// 	close(fd);
// 	exit(EXIT_SUCCESS);
// }
