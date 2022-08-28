/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:17:59 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 17:26:59 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/client_bonus.h"
// static void	printBitC(unsigned char c)
// {
// 	unsigned char	bit;

// 	bit = 1 << 7;
// 	while (bit != 0)
// 	{
// 		if (c & bit)
// 			ft_putchar_fd('1', 1);
// 		else
// 			ft_putchar_fd('0', 1);
// 		bit >>= 1;
// 	}
// 	ft_putchar_fd('\n', 1);
// }
static int	ft_puterr(char *errmsg)
{
	ft_putendl_fd(errmsg, 1);
	return (false);
}

static int	check_args(int argc, char const *argv[], pid_t pid)
{
	size_t	i;
	size_t	len;

	if (argc != 3)
		return (ft_puterr("invalid arg count"));
	i = 0;
	len = ft_strlen(argv[1]);
	while (i < len)
	{
		if (!ft_isdigit(argv[1][i]))
			return (ft_puterr("invalid pid"));
		i++;
	}
	if (pid < DARWIN_PID_MIN || pid > DARWIN_PID_MAX)
		return (ft_puterr("invalid pid of range"));
	return (true);
}

static void	send_char(unsigned char byte, pid_t pid)
{
	unsigned char	bit;
	int				i;

	i = 0;
	while (i < BYTE_COUNT)
	{
		bit = byte & MSB;
		if (bit != MSB)
			kill(pid, SIGUSR1);
		else if (bit == MSB)
			kill(pid, SIGUSR2);
		byte <<= 1;
		i++;
		usleep(WAIT_TIME);
	}
	return ;
}

int	main(int argc, char const *argv[])
{
	pid_t	pid;
	size_t	i;

	pid = ft_atoi(argv[1]);
	if (check_args(argc, argv, pid) == false)
		exit(1);
	i = 0;
	while (argv[2][i] != '\0')
	{
		send_char((unsigned char)argv[2][i], pid);
		i++;
	}
	return (0);
}
