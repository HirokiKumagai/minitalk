/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:17:59 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/28 15:25:37 by hkumagai         ###   ########.fr       */
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

int	main(int argc, char const *argv[])
{
	pid_t	server_pid;
	char	*client_pid;
	size_t	i;

	server_pid = ft_atoi(argv[1]);
	if (check_args(argc, argv, server_pid) == false)
		exit(1);
	i = 0;
	while (argv[2][i] != '\0')
	{
		send_char((unsigned char)argv[2][i], server_pid);
		i++;
	}
	send_char((unsigned char)argv[2][i], server_pid);
	i = 0;
	client_pid = ft_itoa(getpid());
	while (client_pid[i] != '\0')
	{
		send_char((unsigned char)client_pid[i], server_pid);
		i++;
	}
	return (0);
}
