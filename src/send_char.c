#include "../include/send_char.h"
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
