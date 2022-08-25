/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:17:59 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/25 14:35:26 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

static void	handler(int signo)
{
	ft_printf("SIGNO:	%d\n", signo);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char const *argv[])
{
	pid_t				pid;
	struct sigaction	sig;
	int					result;

	pid = getpid();
	ft_printf("PID:	%d\n", pid);
	sig.sa_handler = handler;
	result = sigaction(SIGUSR1, &sig, NULL);
	if (result < 0)
	{
		ft_printf("Error: sigaction()\n");
		exit(1);
	}
	while (true)
	{
		// ft_printf("Working...!\n");
		// ft_printf("%d\n", result);
		sleep(1);
	}

	ft_printf("%d\n", argc);
	ft_printf("%s\n", argv[1]);

	return (0);
}
