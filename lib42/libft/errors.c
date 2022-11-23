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

#include "../_inc/libft.h"

void	exit_message(char *s, int code)
{
	ft_putendl_fd(s, STDERR_FILENO);
	exit(code);
}

bool	ft_error_va(char *errmsg, ...)
{
	va_list		args;
	char		*arg = errmsg;

	write(2, errmsg, ft_strlen(errmsg));
	va_start(args, errmsg);
	while ((arg = va_arg(args, char*)))
		write(2, arg, ft_strlen(arg));
	write(2, "\n", 1);
	va_end(args);
	return false;
}