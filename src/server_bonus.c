/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:17:59 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/29 06:38:26 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server_bonus.h"
static void	get_char(int sig)
{
	if (sig == SIGUSR1 && g_sigchar.count < BYTE_COUNT)
		g_sigchar.bit <<= 1;
	else if (sig == SIGUSR2 && g_sigchar.count < BYTE_COUNT)
	{
		g_sigchar.bit |= 1;
		g_sigchar.bit <<= 1;
	}
	if (g_sigchar.count == BYTE_COUNT)
	{
		if (sig == SIGUSR2)
			g_sigchar.bit |= 1;
	}
}

static void	get_process_num(int sig)
{
	if (sig == SIGUSR1 && g_sigchar.count < BYTE_COUNT)
		g_sigchar.clientPID <<= 1;
	else if (sig == SIGUSR2 && g_sigchar.count < BYTE_COUNT)
	{
		g_sigchar.clientPID |= 1;
		g_sigchar.clientPID <<= 1;
	}
	if (g_sigchar.count == BYTE_COUNT)
	{
		if (sig == SIGUSR2)
			g_sigchar.clientPID |= 1;
	}
}

static void	sigFunc(int sig, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	g_sigchar.count++;
	if (g_sigchar.isBitEnd == false)
		get_char(sig);
	else
		get_process_num(sig);
	if (g_sigchar.count == BYTE_COUNT)
	{
		if (g_sigchar.isBitEnd == false && g_sigchar.bit == '\0')
		{
			g_sigchar.isBitEnd = true;
			g_sigchar.count = 0;
			g_sigchar.bit = 0;
			return ;
		}
		if (g_sigchar.isBitEnd == false)
			ft_putchar_fd(g_sigchar.bit, 1);

		if (g_sigchar.isBitEnd == true && g_sigchar.clientPID == '\0')
		{
			int i = 0;
			while ("\nsend complete"[i] != '\0')
				send_char("\nsend complete"[i++], g_sigchar.clientPIDs);
			send_char("\nsend complete"[i], g_sigchar.clientPIDs);
			g_sigchar.isBitEnd = false;
			g_sigchar.clientPIDs = 0;
		}
		if (g_sigchar.isBitEnd == true && g_sigchar.clientPID != '\0')
			g_sigchar.clientPIDs = \
				g_sigchar.clientPIDs * 10 + (g_sigchar.clientPID - '0');

		g_sigchar.count = 0;
		g_sigchar.bit = 0;
		g_sigchar.clientPID = 0;
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
