#ifndef SEND_CHAR_H
# define SEND_CHAR_H
# define BYTE_COUNT 8
# define WAIT_TIME 3000
# define MSB 128
# include <signal.h>
# include <unistd.h>

void	send_char(unsigned char byte, pid_t pid);
#endif
