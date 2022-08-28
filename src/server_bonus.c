/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:17:59 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/28 17:08:54 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server_bonus.h"
static void	sigFunc(int sig, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	g_sigchar.count++;
	if (sig == SIGUSR1 && g_sigchar.count < BYTE_COUNT)
		g_sigchar.bit <<= 1;
	else if (sig == SIGUSR2 && g_sigchar.count < BYTE_COUNT)
	{
		g_sigchar.isEnd = false;
		g_sigchar.bit |= 1;
		g_sigchar.bit <<= 1;
	}
	if (g_sigchar.count == BYTE_COUNT)
	{
		if (sig == SIGUSR2)
			g_sigchar.bit |= 1;
		ft_putchar_fd(g_sigchar.bit, 1);
		if (g_sigchar.bit == '\0')
			ft_putstr_fd("end", 1);
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

int	main(void)
{
	pid_t		pid;

	pid = getpid();
	ft_printf("PID:	%d\n", pid);
	receive_signal();
	while (true)
		pause();
	return (0);
}