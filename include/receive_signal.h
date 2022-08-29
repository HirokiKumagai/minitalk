#ifndef RECEIVE_SIGNAL_H
# define RECEIVE_SIGNAL_H
# define EXIT_ERROR 1
# define BYTE_COUNT 8
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../lib/ft_printf/include/ft_printf.h"
# include "./send_message.h"

void	sigFunc(int sig, siginfo_t *info, void *ucontext);
void	receive_signal(void);
void	get_char(int sig);
void	get_process_num(int sig);
void	tmpfunc(void);

typedef struct s_sigchar
{
	int				count;
	unsigned char	bit;
	bool			isBitEnd;
	unsigned char	clientPID;
	unsigned int	clientPIDs;
}	t_sigchar;

extern t_sigchar	g_sigchar;
#endif
