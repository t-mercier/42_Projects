/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   single_linkedlist.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 19:18:04 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 20:57:11 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>

/*
 * len : Vector real length
 * size : Vector max size
 * esz : Element size
 */

typedef struct s_vector
{
	void	*item;
	size_t	size;
	size_t	len;
	size_t	esz;
}			t_vector;

t_vector	*vector_init(size_t size);
void		vector_append(t_vector *v, void *x);
void		free_vector(t_vector *v);

#endif
