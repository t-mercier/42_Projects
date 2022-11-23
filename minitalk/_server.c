/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 20:45:34 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/18 20:45:34 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// SERVER

void	sig_usr(int sig, siginfo_t *info, void *context)
{
	static int bit = 0;
	static unsigned char c = 0;

	(void)context;
	if (kill(info->si_pid, 0) < 0)
	{
		ft_printf("ERROR : cant send sig to pid : %d\n", info->si_pid);
		exit(EXIT_FAILURE);
	}
	c = c << 1;
	c |= sig == SIGUSR1;
	if (bit < 0)
		bit = __CHAR_BIT__ * sizeof(c) - 1;
	if (++bit == CHAR_BIT)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
	else if (!bit && !c)
		kill(info->si_pid, SIGUSR2);
	bit--;
	kill(info->si_pid, SIGUSR1);
}

int	main(int ac, char **av)
{
	/* Register signal handlers. */
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	ft_printf("PID: [ %d ]", getpid());
	while (1)
		sleep(20);
}
//
//void sig_set_handler(int sign, void *handler)
//{
//	struct sigaction act;
//
//	act.sa_sigaction = handler;
//	act.sa_flags = SA_SIGINFO;
//
//	sigaction(sign, &act, NULL);
//}

//int	main(void)
//{
//	init_sig(SIGUSR1, &sig_usr);
//	init_sig(SIGUSR2, &sig_usr);
//	ft_printf("pid: %d", getpid());
//	while (1)
//		sleep(1);
//}

