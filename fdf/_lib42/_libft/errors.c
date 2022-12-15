/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_and_errors.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/13 10:48:50 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/13 10:48:50 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	exit_message(char *s, int code)
{
	ft_printf("%s%s", RED, s);
	exit(code);
}
