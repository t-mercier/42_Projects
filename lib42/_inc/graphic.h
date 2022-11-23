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

typedef struct s_matrice {
	double		r11;
	double		r12;
	double		r13;
	double		r21;
	double		r22;
	double		r23;
	double		r31;
	double		r32;
	double		r33;
}t_matrice;

void build_matrice();


#endif