/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:17:59 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/25 14:59:08 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

static void	handler(int signo)
{
	ft_printf("SIGNO:	%d\n", signo);
	exit(EXIT_SUCCESS);
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
	act.sa_handler = handler;
	if (!sigaction(SIGUSR1, &act, NULL))
	{
		ft_printf("Error: sigaction()\n");
		exit(1);
	}
	if (!sigaction(SIGUSR2, &act, NULL))
	{
		ft_printf("Error: sigaction()\n");
		exit(1);
	}
	while (true)
	{
		ft_printf("Working...!\n");
		sleep(1);
	}
	return (0);
}
