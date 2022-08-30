/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:26:29 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/30 04:26:31 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# define BYTE_COUNT 8
# define MSB 128
# define WAIT_TIME 3000
# define DARWIN_PID_MIN 100
# define DARWIN_PID_MAX 99998
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <stdbool.h>
# include "../lib/ft_printf/include/ft_printf.h"

#endif
