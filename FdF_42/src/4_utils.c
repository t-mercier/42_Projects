/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   4_utils.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 21:07:55 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"


void ft_scrollhook(double dx, double dy, void* param)
{
    // Simple up or down detection.
    if (dy > 0)
        puts("Up!");
    else if (dy < 0)
        puts("Down!");

    // Can also detect a mousewheel that go along the X (e.g: MX Master 3)
    if (dx < 0)
        puts("Sliiiide to the left!");
    else if (dx > 0)
        puts("Sliiiide to the right!");
}

void	*check_malloc(void	*ptr)
{
	if (ptr != NULL)
		return (ptr);
	perror(NULL);
	return 0;
}

void    exit_success_message(char *s)
{
	ft_putendl_fd(s, STDERR_FILENO);
	exit(EXIT_SUCCESS);
}

void    error(void)
{
	char    *s;

	s = ft_strdup(mlx_strerror(mlx_errno));
	ft_putendl_fd(s, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void    exit_message(char *s, int code)
{
	ft_putendl_fd(s, STDERR_FILENO);
	exit(code);
}