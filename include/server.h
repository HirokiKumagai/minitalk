/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:26:45 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/30 04:26:46 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# define EXIT_ERROR 1
# define BYTE_COUNT 8

# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include "../lib/ft_printf/include/ft_printf.h"

typedef struct s_sigchar
{
	int				count;
	unsigned char	bit;
}				t_sigchar;

t_sigchar	g_sigchar = {0, 0};

#endif
