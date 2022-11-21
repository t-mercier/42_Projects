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


void sig_send_val ( pid_t id, int signo, int val )
{
	union sigval *sigdata;

	sigdata = malloc ( sizeof ( union sigval ) );
	sigdata -> sival_int = val;

	sigqueue(id,signo, *sigdata);

	free(sigdata);
}

void sig_send_msg (pid_t id, int signo, char *msg)
{
	union sigval *sigdata;

	sigdata = malloc (sizeof(union sigval));
	sigdata->sival_ptr = msg;

	sigqueue(id, signo, *sigdata );

	free (sigdata);
}

void sig_set_handler(int signo, void *handler )
{
	struct sigaction *act;
	act = malloc (sizeof(struct sigaction));
	act->sa_sigaction = handler;
	act->sa_flags = SA_SIGINFO;

	sigaction(signo, act, NULL);
}

void signal_gen(char *av)
{
	while (1)
	{
		sig_send_msg(getppid (), SIGUSR1, av[1]);
		sleep(2);
	}
}

void signal_handler(int sig, siginfo_t *siginfo, void *context)
{

	printf ("message = %s\n", siginfo->si_value);

}

int	main(int ac, char **av)
{

	ft_printf("PID: %d", getpid());
	sig_send_msg(getpid(), SIGUSR1, av[1]);

	while (1)
		sleep(1);
}

