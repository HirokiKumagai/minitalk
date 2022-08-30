/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:26:06 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/30 04:26:08 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/receive_signal.h"

void	receive_signal( \
	void (*sigFunc)(int sig, siginfo_t *info, void *ucontext))
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
