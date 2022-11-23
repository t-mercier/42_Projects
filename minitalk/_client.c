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

int s_received = 0;

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

//https://www.folkstalk.com/tech/kill-sigusr2-with-code-examples/

void	handle_char(int pid, unsigned char c)
{
	int i;
	unsigned char mask;

	i = 7;
	mask = 1u << i;
	while (mask)
	{
		s_received = 0;
		if (mask & c)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		if (!s_received)
			pause();
		i--;
		mask >>= 1;
	}
}

void	handle_string(int pid, char *msg)
{
	int i;

	i = -1;
	while (msg[++i])
		handle_char(pid, msg[i]);
	handle_char(pid, 0);
}

void	sig_usr(int sig)
{
	if (sig == SIGUSR1)
		s_received = 1;
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
	handle_string(av[2], pid);
	while (1)
		sleep(1);

}

