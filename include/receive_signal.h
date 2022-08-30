/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_signal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:26:36 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/30 04:26:38 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECEIVE_SIGNAL_H
# define RECEIVE_SIGNAL_H
# define EXIT_ERROR 1
# define BYTE_COUNT 8
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../lib/ft_printf/include/ft_printf.h"
# include "./send_message.h"

void	receive_signal(\
			void (*sigFunc)(int sig, siginfo_t *info, void *ucontext));

typedef struct s_sigchar
{
	int				count;
	unsigned char	bit;
	bool			is_bit_end;
	unsigned char	pid_bit;
	unsigned int	client_pid;
}	t_sigchar;

extern t_sigchar	g_sigchar;
#endif
