/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:17:59 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/04 13:41:30 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/client_bonus.h"
static int	ft_puterr(char *errmsg)
{
	ft_putendl_fd(errmsg, 1);
	return (false);
}

static int	check_args(int argc, char const *argv[])
{
	size_t	i;
	size_t	len;
	pid_t	pid;

	if (argc != 3)
		return (ft_puterr("invalid arg count"));
	i = 0;
	pid = ft_atoi(argv[1]);
	len = ft_strlen(argv[1]);
	while (i < len)
	{
		if (!ft_isdigit(argv[1][i]))
			return (ft_puterr("invalid pid"));
		i++;
	}
	if (kill(pid, 0) < 0)
		return (ft_puterr("The pid does not exist."));
	if (pid < DARWIN_PID_MIN || pid > DARWIN_PID_MAX)
		return (ft_puterr("invalid pid of range"));
	return (true);
}

int	main(int argc, char const *argv[])
{
	pid_t	server_pid;
	char	*client_pid;

	if (check_args(argc, argv) == false)
		exit(EXIT_ERROR);
	server_pid = ft_atoi(argv[1]);
	receive_signal(output_signal);
	send_message((char *)argv[2], server_pid);
	client_pid = ft_itoa(getpid());
	send_message(client_pid, server_pid);
	while (true)
		pause();
	return (0);
}
