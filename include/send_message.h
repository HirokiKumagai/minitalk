/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:26:39 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/30 04:26:41 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEND_MESSAGE_H
# define SEND_MESSAGE_H
# define BYTE_COUNT 8
# define WAIT_TIME 3000
# define MSB 128
# include <signal.h>
# include <unistd.h>

void	send_char(unsigned char byte, pid_t pid);
void	send_message(char *str, pid_t pid);
#endif
