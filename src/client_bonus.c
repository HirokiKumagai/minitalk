/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:17:59 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/29 21:45:15 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/client_bonus.h"
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

static void	sigFunc(int sig, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	g_sigchar.count++;
	if (sig == SIGUSR1 && g_sigchar.count < BYTE_COUNT)
		g_sigchar.bit <<= 1;
	else if (sig == SIGUSR2 && g_sigchar.count < BYTE_COUNT)
	{
		g_sigchar.isBitEnd = false;
		g_sigchar.bit |= 1;
		g_sigchar.bit <<= 1;
	}
	if (g_sigchar.count == BYTE_COUNT)
	{
		if (sig == SIGUSR2)
			g_sigchar.bit |= 1;
		ft_putchar_fd(g_sigchar.bit, 1);
		if (g_sigchar.bit == '\0')
		{
			ft_putchar_fd('\n', 1);
			exit(EXIT_SUCCESS);
		}
		g_sigchar.bit = 0;
		g_sigchar.count = 0;
	}
}

static void	receive_signal(void)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(struct sigaction));
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sigFunc;
	if (sigaction(SIGUSR1, &act, NULL) != 0)
	{
		ft_printf("Error: sigaction()\n");
		exit(EXIT_ERROR);
	}
	if (sigaction(SIGUSR2, &act, NULL) != 0)
	{
		ft_printf("Error: sigaction()\n");
		exit(EXIT_ERROR);
	}
}

int	main(int argc, char const *argv[])
{
	pid_t	server_pid;
	char	*client_pid;
	size_t	i;

	server_pid = ft_atoi(argv[1]);
	if (check_args(argc, argv, server_pid) == false)
		exit(EXIT_ERROR);
	receive_signal();
	i = 0;
	while (argv[2][i] != '\0')
		send_char((unsigned char)argv[2][i++], server_pid);
	send_char((unsigned char)argv[2][i], server_pid);
	i = 0;
	client_pid = ft_itoa(getpid());
	while (client_pid[i] != '\0')
		send_char((unsigned char)client_pid[i++], server_pid);
	send_char((unsigned char)client_pid[i], server_pid);
	while (true)
		pause();
	return (0);
}
