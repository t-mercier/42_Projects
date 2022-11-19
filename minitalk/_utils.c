/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   _utils.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 18:44:29 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/19 18:44:29 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	init_sig()
{

}

void	printout_pid(void)
{
	char	*sp;

	sp = ft_itoa(getpid(), 10);
	if (!sp)
		exit_message("ERROR [ failed itoa ]", 1);
	ft_putstr_fd("[ PID ] " , 1);
	ft_putendl_fd(sp, 1);
	free(sp);
}