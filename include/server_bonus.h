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


typedef struct s_sigchar
{
	int				count;
	unsigned char	bit;
	bool			isEnd;
}				t_sigchar;

t_sigchar	g_sigchar = {0, 0, true};

#endif
