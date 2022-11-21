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
	char *s;

	s = "usage: ./client [server-pid] [message]\n";
	write(1, s, ft_strlen(s));
	exit(0);
}

void	invalid_pid(char *s)
{
	ft_printf("%s is an invalid pid\n", s);
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

//sig_handler(getpid(), SIGUSR1, av[1])
void	sig_usr(int sig)
{
	if (sig == SIGUSR1)
		g_bit_control = 1;
	else if (sig == SIGUSR2)
	{
		ft_printf("Message received !\n");
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **av)
{
	pid_t	pid;

	if (argc != 3)
		usage();
	signal(SIGUSR1, &sig_usr);
	signal(SIGUSR2, &sig_usr);
	pid = ft_atoi(av[1]);
	if (!pid)
		invalid_pid(av[1]);
	send_str(av[2], pid);
	while (1)
		sleep(1);

}

