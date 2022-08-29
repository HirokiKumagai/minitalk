#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H
# define EXIT_ERROR 1
# define BYTE_COUNT 8

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include "../lib/ft_printf/include/ft_printf.h"
# include "./send_char.h"

typedef struct s_sigchar
{
	int				count;
	unsigned char	bit;
	bool			isBitEnd;
	unsigned char	clientPID;
	unsigned int	clientPIDs;
}				t_sigchar;

t_sigchar	g_sigchar = {0, 0, false, 0, 0};

#endif
