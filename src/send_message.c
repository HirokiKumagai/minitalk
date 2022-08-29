#include "../include/send_message.h"
#include <stdio.h>

void	send_char(unsigned char byte, pid_t pid)
{
	unsigned char	bit;
	int				i;

	i = 0;
	while (i < BYTE_COUNT)
	{
		bit = byte & MSB;
		if (bit != MSB)
			kill(pid, SIGUSR1);
		else if (bit == MSB)
			kill(pid, SIGUSR2);
		byte <<= 1;
		i++;
		usleep(WAIT_TIME);
	}
	return ;
}

void	send_message(char *str, pid_t pid)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		send_char(str[i++], pid);
	send_char(str[i], pid);
}
