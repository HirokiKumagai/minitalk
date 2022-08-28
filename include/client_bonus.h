#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# define BYTE_COUNT 8
# define WAIT_TIME 3000
# define DARWIN_PID_MIN 100
# define DARWIN_PID_MAX 99998
# define EXIT_ERROR 1
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <stdbool.h>
# include "../lib/ft_printf/include/ft_printf.h"
# include "./send_char.h"

typedef struct s_sigchar
{
	int				count;
	unsigned char	bit;
	bool			isEnd;
}				t_sigchar;

t_sigchar	g_sigchar = {0, 0, true};

#endif
