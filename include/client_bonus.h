#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H
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
# include "./receive_signal.h"
# include "./output_signal.h"

t_sigchar	g_sigchar = {0, 0, false, 0, 0};
#endif
