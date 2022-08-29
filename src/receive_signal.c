#include "../include/receive_signal.h"

void	receive_signal( \
	void (*sigFunc)(int sig, siginfo_t *info, void *ucontext))
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(struct sigaction));
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sigFunc;
	if (sigaction(SIGUSR1, &act, NULL) != 0)
	{
		ft_printf("Error: sigaction()\n");
		exit(EXIT_ERROR);
	}
	if (sigaction(SIGUSR2, &act, NULL) != 0)
	{
		ft_printf("Error: sigaction()\n");
		exit(EXIT_ERROR);
	}
}

void	sigFunc(int sig, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	g_sigchar.count++;
	if (g_sigchar.isBitEnd == false)
		get_char(sig);
	else if (g_sigchar.isBitEnd == true)
		get_process_num(sig);
	if (g_sigchar.count == BYTE_COUNT)
	{
		if (g_sigchar.isBitEnd == false && g_sigchar.bit == '\0')
		{
			g_sigchar.isBitEnd = true;
			g_sigchar.count = 0;
			g_sigchar.bit = 0;
			return ;
		}
		tmpfunc();
		g_sigchar.count = 0;
		g_sigchar.bit = 0;
		g_sigchar.clientPID = 0;
	}
}

void	get_char(int sig)
{
	if (sig == SIGUSR1 && g_sigchar.count < BYTE_COUNT)
		g_sigchar.bit <<= 1;
	else if (sig == SIGUSR2 && g_sigchar.count < BYTE_COUNT)
	{
		g_sigchar.bit |= 1;
		g_sigchar.bit <<= 1;
	}
	if (g_sigchar.count == BYTE_COUNT)
	{
		if (sig == SIGUSR2)
			g_sigchar.bit |= 1;
	}
}

void	get_process_num(int sig)
{
	if (sig == SIGUSR1 && g_sigchar.count < BYTE_COUNT)
		g_sigchar.clientPID <<= 1;
	else if (sig == SIGUSR2 && g_sigchar.count < BYTE_COUNT)
	{
		g_sigchar.clientPID |= 1;
		g_sigchar.clientPID <<= 1;
	}
	if (g_sigchar.count == BYTE_COUNT)
	{
		if (sig == SIGUSR2)
			g_sigchar.clientPID |= 1;
	}
}

void	tmpfunc(void)
{
	if (g_sigchar.isBitEnd == false)
		ft_putchar_fd(g_sigchar.bit, 1);
	if (g_sigchar.isBitEnd == true && g_sigchar.clientPID == '\0')
	{
		send_message("\nsend complete", g_sigchar.clientPIDs);
		g_sigchar.isBitEnd = false;
		g_sigchar.clientPIDs = 0;
	}
	if (g_sigchar.isBitEnd == true && g_sigchar.clientPID != '\0')
		g_sigchar.clientPIDs = \
			g_sigchar.clientPIDs * 10 + (g_sigchar.clientPID - '0');
}
