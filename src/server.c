/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:17:59 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/25 13:20:14 by hkumagai         ###   ########.fr       */
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

	pid = getpid();
	ft_printf("PID:	%d\n", pid);
	sig.sa_handler = handler;
	sigaction(SIGINT, &sig, NULL);
	while (true)
	{
		ft_printf("Working...!\n");
		sleep(1);
	}

	ft_printf("%d\n", argc);
	ft_printf("%s\n", argv[1]);

	return (0);
}
