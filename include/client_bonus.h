#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H
# define EXIT_ERROR 1
# define BYTE_COUNT 8
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
# include "./send_message.h"

typedef struct s_sigchar
{
	int				count;
	unsigned char	bit;
	bool			isBitEnd;
}				t_sigchar;

t_sigchar	g_sigchar = {0, 0, true};

#endif
