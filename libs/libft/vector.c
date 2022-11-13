/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   growth_array.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 21:07:55 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void *free_vector(t_vector *v)
{
	while(v->len--)
		free(v->item);
	free(v);
	exit(1);
}

t_vector *vector_init(size_t size)
{
	t_vector *v;
	v = malloc(sizeof(t_vector) * size);
	if (!v)
		exit(0);
	v->len = 0;
	v->buff = 2;
	v->esz = size;
	v->item = malloc(v->esz * v->buff);
	if (!v->item)
		return (free_vector(&(*v)));
	return v;
}

void vector_append(t_vector *v, void *x)
{
	if (v->len == v->buff)
	{
		v->item = ft_realloc(v->item, v->buff * 2 * v->esz, v->esz * v->buff);
		v->buff *= 2;
	}
	ft_memcpy(v->item + v->len++ * v->esz, x, v->esz);
}
