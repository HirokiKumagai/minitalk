/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_signal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:26:34 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/30 04:26:35 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_SIGNAL_H
# define OUTPUT_SIGNAL_H
# define EXIT_SUCCESS 0
# define EXIT_ERROR 1
# define BYTE_COUNT 8
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../lib/ft_printf/include/ft_printf.h"
# include "./receive_signal.h"
void	output_signal(int sig, siginfo_t *info, void *ucontext);
void	dialogue_func(int sig, siginfo_t *info, void *ucontext);
#endif
