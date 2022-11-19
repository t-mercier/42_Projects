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


int	main(void)
{

	ft_printf("pid: %d", getpid());
	while (1)
		sleep(1);
}

