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

void sig_handler(int sig)
{
	static int i = 0;
	static unsigned char c = 0;

	c = c << 1;
	c |= sig == SIGUSR2;
	if (++i == CHAR_BIT)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}

}

char sym = 'X';

void sh1(int st)
{
	signal(SIGUSR1, sh1);
	fscanf(fp,"%c",&sym);
}

void sh2(int st)
{
	fp = fopen("foo","r");
	setbuf(fp,NULL);
}

int	main(int ac, char **av)
{

	ft_printf("PID: [ %d ]", getpid());

//	sig_handler(getpid(), SIGUSR1, av[1]);

	/* Register signal handlers. */
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		sleep(20);
}
