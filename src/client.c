/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:17:59 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 08:49:41 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/client.h"
static void	printBitC(unsigned char c)
{
	unsigned char	bit;

	bit = 1 << 7;
	while (bit != 0)
	{
		if (c & bit)
			ft_putchar_fd('1', 1);
		else
			ft_putchar_fd('0', 1);
		bit >>= 1;
	}
	ft_putchar_fd('\n', 1);
}

static void	send_char(unsigned char byte, pid_t pid)
{
	unsigned char	bit;
	int				i;

	i = 0;
	while (i < 8)
	{
		bit = byte & 128;
		if (bit != 128)
			kill(pid, SIGUSR1);
		else if (bit == 128)
			kill(pid, SIGUSR2);
		byte <<= 1;
		i++;
		usleep(2000);
	}
	return ;
}

int	main(int argc, char const *argv[])
{
	pid_t	pid;
	size_t	i;

	(void)argc;
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		printBitC(argv[2][i]);
		send_char((unsigned char)argv[2][i++], pid);
	}

	return (0);
}
