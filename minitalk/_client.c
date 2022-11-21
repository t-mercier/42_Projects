/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   _client.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 20:49:27 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/18 20:49:27 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_bit_control;

void	usage(void)
{
	write(1, "usage: ./client [server-pid] [message]\n", 39);
	exit(0);
}

int kill(pidt pid, int sig);

//https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L12/Class.html

void	send_char(char c, pid_t pid)
{
	int	bit;

	bit = __CHAR_BIT__ * sizeof(c) - 1;
	while (bit >= 0)
	{
		if (kill(pid, 0) < 0)
		{
			ft_printf("ERROR : cant send sig to pid : %d\n", pid);
			exit(EXIT_FAILURE);
		}
		g_bit_control = 0;
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		while (g_bit_control != 1)
			usleep(10);
	}

}

void	send_str(char *str, pid_t pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(str[i], pid);
		i++;
	}
	send_char(0, pid);
}

void sig_set_handler(int sign, void *handler)
{
	struct sigaction act;

	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;

	sigaction(sign, &act, NULL);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("Usage : ./client <pid> <string to send>\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (!pid)
		usage();
	signal(SIGUSR1, success);
	g_bit_control = 1;
	send_str(argv[2], pid);
	sig_set_handler(pid, argv[2]);
	while (1)
		usleep (1000);
}

