/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 20:45:57 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/18 20:45:57 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
 * The server reveals its PID and starts listening.
 * The client takes a string from standard input,
 * encodes it to binary and starts streaming it
 * to the server byte by byte.
 * The server receives the signals and decodes them.
 * The server prints the received string.
 */

# include <signal.h>
# include "../lib42/_inc/lib42.h"

void	init_sig();
void	printout_pid(void);
