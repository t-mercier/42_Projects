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

#include "../inc/libft.h"
#include "../inc/vectors.h"

void	free_vector(t_vector *v)
{
	free(v->item);
	free(v);
}

t_vector	*vector_init(size_t esz)
{
	t_vector	*v;

	v = ft_malloc(sizeof(t_vector));
	v->len = 0;
	v->size = 2;
	v->esz = esz;
	v->item = ft_malloc(v->esz * v->size);
	return (v);
}

void	vector_append(t_vector *v, void *x)
{
	if (v->len == v->size)
	{
		v->item = ft_realloc(v->item, v->size * 2 * v->esz, v->esz * v->size);
		if (!v->item)
			exit_message("[ MALLOC FAIL ]\n\n", 1);
		v->size *= 2;
	}
	ft_memcpy(v->item + (v->len++) * v->esz, x, v->esz);
}
