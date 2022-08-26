/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:17:59 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 15:28:13 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

static void	sigFunc(int sig, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	g_tmp.count++;
	if (sig == SIGUSR1 && g_tmp.count <= 7)
		g_tmp.bit <<= 1;
	else if (sig == SIGUSR2 && g_tmp.count <= 7)
	{
		g_tmp.bit |= 1;
		g_tmp.bit <<= 1;
	}
	if (g_tmp.count == 8)
	{
		if (sig == SIGUSR2)
			g_tmp.bit |= 1;
		ft_putchar_fd(g_tmp.bit, 1);
		g_tmp.bit = 0;
		g_tmp.count = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	act;

	pid = getpid();
	ft_printf("PID:	%d\n", pid);
	ft_bzero(&act, sizeof(struct sigaction));
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sigFunc;
	if (sigaction(SIGUSR1, &act, NULL) != 0)
	{
		ft_printf("Error: sigaction()\n");
		exit(1);
	}
	if (sigaction(SIGUSR2, &act, NULL) != 0)
	{
		ft_printf("Error: sigaction()\n");
		exit(1);
	}
	while (true)
	{
		pause();
	}
	return (0);
}
