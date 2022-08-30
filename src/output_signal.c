/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:25:59 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/30 04:26:01 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/output_signal.h"
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
	usleep(10);
}

static void	get_sender_pid(int sig)
{
	if (sig == SIGUSR1 && g_sigchar.count < BYTE_COUNT)
		g_sigchar.pid_bit <<= 1;
	else if (sig == SIGUSR2 && g_sigchar.count < BYTE_COUNT)
	{
		g_sigchar.pid_bit |= 1;
		g_sigchar.pid_bit <<= 1;
	}
	if (g_sigchar.count == BYTE_COUNT)
	{
		if (sig == SIGUSR2)
			g_sigchar.pid_bit |= 1;
	}
	usleep(10);
}

static void	send_back_signal(void)
{
	if (g_sigchar.is_bit_end == false)
		ft_putchar_fd(g_sigchar.bit, 1);
	if (g_sigchar.is_bit_end == true && g_sigchar.pid_bit == '\0')
	{
		send_message("\nsend complete", g_sigchar.client_pid);
		g_sigchar.is_bit_end = false;
		g_sigchar.client_pid = 0;
	}
	if (g_sigchar.is_bit_end == true && g_sigchar.pid_bit != '\0')
		g_sigchar.client_pid = \
			g_sigchar.client_pid * 10 + (g_sigchar.pid_bit - '0');
}

void	output_signal(int sig, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	g_sigchar.count++;
	if (sig == SIGUSR1 && g_sigchar.count < BYTE_COUNT)
		g_sigchar.bit <<= 1;
	else if (sig == SIGUSR2 && g_sigchar.count < BYTE_COUNT)
	{
		g_sigchar.is_bit_end = false;
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

void	dialogue_func(int sig, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	g_sigchar.count++;
	if (g_sigchar.is_bit_end == false)
		get_char(sig);
	else if (g_sigchar.is_bit_end == true)
		get_sender_pid(sig);
	if (g_sigchar.count == BYTE_COUNT)
	{
		if (g_sigchar.is_bit_end == false && g_sigchar.bit == '\0')
		{
			g_sigchar.is_bit_end = true;
			g_sigchar.count = 0;
			g_sigchar.bit = 0;
			return ;
		}
		send_back_signal();
		g_sigchar.count = 0;
		g_sigchar.bit = 0;
		g_sigchar.pid_bit = 0;
	}
}
