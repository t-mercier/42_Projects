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
//
//#include "minitalk.h"
//
//void	usage(void)
//{
//	write(1, "usage: ./client [server-pid] [message]\n", 39);
//	exit(0);
//}
//
//int	g_bit_control;
//
//void	send_char(char c, pid_t pid)
//{
//
//}
//
//void	send_str(char *str, pid_t pid)
//{
//	int	i;
//
//	i = 0;
//	while (str[i])
//	{
//		send_char(str[i], pid);
//		i++;
//	}
//	send_char(0, pid);
//}
//
//void	sig_usr(int sig)
//{
//	if (sig == SIGUSR1)
//		g_bit_control = 1;
//	else if (sig == SIGUSR2)
//	{
//		ft_printf("Message received !\n");
//		exit(EXIT_SUCCESS);
//	}
//}
//
//int	main(int argc, char **argv)
//{
//	pid_t	pid;
//
//	if (argc != 3)
//	{
//		ft_printf("Usage : ./client <pid> <string to send>\n");
//		exit(EXIT_FAILURE);
//	}
//	signal(SIGUSR1, &sig_usr);
//	signal(SIGUSR2, &sig_usr);
//	pid = ft_atoi(argv[1]);
//	if (!pid)
//		usage();
//	send_str(argv[2], pid);
//	while (1)
//		sleep(1);
//}
//
