/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ternaries.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/13 10:22:13 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/13 10:22:13 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

long	tern_long(int condition, long _true, long _false)
{
	if (condition)
		return (_true);
	else
		return (_false);
}

int	tern_int(int condition, int _true, int _false)
{
	if (condition)
		return (_true);
	else
		return (_false);
}

size_t	tern_size_t(int condition, size_t _true, size_t _false)
{
	if (condition)
		return (_true);
	else
		return (_false);
}

char	tern_char(int condition, char _true, char _false)
{
	if (condition)
		return (_true);
	else
		return (_false);
}

char	*tern_str(int condition, char *_true, char *_false)
{
	if (condition)
		return (_true);
	else
		return (_false);
}
