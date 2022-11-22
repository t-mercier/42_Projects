/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   3_algo.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 21:07:55 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#define DEG2RAD (M_PI / 180)


static t_rotate rotate_point(t_matrice a, t_vertex p_in)     //Input coords in order (x,y,z)
{
	t_rotate p_out;

	p_out.x = a.r11 * p_in.x + a.r12 * p_in.y + a.r13 * p_in.z;
	p_out.y = a.r21 * p_in.x + a.r22 * p_in.y + a.r23 * p_in.z;
	p_out.z = a.r31 * p_in.x + a.r32 * p_in.y + a.r33 * p_in.z;
	return p_out; //Output coords in order (x,y,z)
}

static t_rotate matrix_to_angle(t_matrice a)
{
	t_rotate r;

	r.pitch = -asin( a.r31 );

	if (a.r31 == 1)
	{
		r.yaw = 0.0;
		r.roll = atan2( -a.r12, -a.r13 );
	}
	else if (a.r31 == -1 ){
		r.yaw = 0.0;
		r.roll = atan2(a.r12, a.r13);
	}
	else{
		r.yaw = atan2(a.r21, a.r11);
		r.roll = atan2(a.r32, a.r33);
	}
	return r;   //Euler angles in order yaw, pitch, roll
}


static void init_rotate(t_fdf *fdf, t_rotate *c, t_rotate *s)
{
	c->x = (float) cos(fdf->r.roll * DEG2RAD);
	s->x = (float) sin(fdf->r.roll * DEG2RAD);
	c->y = (float) cos(fdf->r.pitch * DEG2RAD);
	s->y = (float) sin(fdf->r.pitch * DEG2RAD);
	c->z = (float) cos(fdf->r.yaw * DEG2RAD);
	s->z = (float) sin(fdf->r.yaw * DEG2RAD);

}


static void rotate_x(t_fdf *fdf, t_vertex *p)
{
	t_vertex t;
	double angle;

	t = *p;
	angle = degree_to_radians(fdf->r.yaw);
	p->x = t.x;
	p->y = t.y * cos(angle) + t.z * -sin(angle);
	p->z = t.y * sin(angle) + t.z * cos(angle);
}

static void rotate_y(t_fdf *fdf, t_vertex *p)
{
	t_vertex t;
	double angle;

	t = *p;
	angle = degree_to_radians(fdf->r.pitch);
	p->x = t.x * cos(angle) + t.z * sin(angle);
	p->y = t.y;
	p->z = t.x * -sin(angle) + t.z * cos(angle);
}

static void rotate_z(t_fdf *fdf, t_vertex *p)
{
	t_vertex t;
	double angle;

	t = *p;
	angle = degree_to_radians(fdf->r.roll);
	p->x = t.x * cos(angle) + t.y * -sin(angle);
	p->z = t.x * sin(angle) + t.y * cos(angle);
	p->y = t.z;
}

static void projection_down(t_fdf *fdf, t_vertex _0, t_vertex p)
{
	t_rotate 	d;
	t_vertex	c;
	t_rotate	s;
	t_vertex	t;
	t_vertex	_1;
	t_matrice a = (t_matrice){};

//	init_rotate(fdf, &c, &s);
	rotate_x(fdf, &c);
	a.r11 = c.y * c.z;
	a.r12 = s.x * s.y * c.z - c.x * s.z;
	a.r13 = s.x * s.z + c.x * s.y * c.z;
	rotate_y(fdf, &c);
	a.r21 = c.y * s.z;
	a.r22 = c.x * c.z + s.x * s.y* s.z;
	a.r23 = c.x * s.y * s.z - s.x * c.z;
	rotate_z(fdf, &c);
	a.r31 = -s.y;
	a.r32 = s.x * c.y;
	a.r33 = c.x * c.y;

	t_rotate angle;

	angle.pitch = -asin( a.r31 );
	if( a.r31 == 1 ){
		angle.yaw = 0.0;             //yaw = 0
		angle.roll = atan2( -a.r12, -a.r13 );    //Roll
	}

		//Gymbal lock: pitch = 90
	else if( a.r31 == -1 ){
		angle.yaw = 0.0;             //yaw = 0
		angle.roll = atan2( a.r12, a.r13 );    //Roll
	}
		//General solution
	else{
		angle.yaw = atan2(  a.r21, a.r11 );
		angle.roll = atan2(  a.r32, a.r33 );
	}

	t.x = (p.x * fdf->tile_size);
	t.y = ((p.y + 1) * fdf->tile_size);
	t.z = -(p.data.z * (fdf->tile_size / 5));

//	d.x = c.y * (s.z * t.y + c.z * t.x) - s.y * t.z;
//	d.y = s.x * (c.y * t.z + s.y * (s.z * t.y + c.z * t.x)) + c.x * (c.z * t.y - s.z * t.x);
//	d.z = c.x * (c.y * t.z + s.y * (s.z * t.y + c.z * t.x)) - s.x * (c.z * t.y - s.z * t.x);
	d = rotate_point(a, t);
	_1.x = (int)((d.x - d.y) * (cos(0.523599)))  + fdf->x_offset;
	_1.y = (int)((d.x + d.y) * (0.5 * sin(0.523599)) - (d.z * 0.5 * 0.2)) + fdf->y_offset;
	drawline(fdf->img, _0, _1,  color(_0, _1));

}

static void	projection_right(t_fdf *fdf, t_vertex _0, t_vertex p)
{
	t_rotate 	d;
	t_vertex	c;
	t_rotate	s;
	t_vertex	t;
	t_vertex	_1;
	t_matrice a = (t_matrice){};

	rotate_x(fdf, &c);
	a.r11 = c.y * c.z;
	a.r12 = s.x * s.y * c.z - c.x * s.z;
	a.r13 = s.x * s.z + c.x * s.y * c.z;
	rotate_y(fdf, &c);
	a.r21 = c.y * s.z;
	a.r22 = c.x * c.z + s.x * s.y* s.z;
	a.r23 = c.x * s.y * s.z - s.x * c.z;
	rotate_z(fdf, &c);
	a.r31 = -s.y;
	a.r32 = s.x * c.y;
	a.r33 = c.x * c.y;
//	fdf->r = matrix_to_angle(a);

	t.x = ((p.x + 1) * fdf->tile_size);
	t.y = (p.y * fdf->tile_size);
	t.z = -(p.data.z * (fdf->tile_size / 5));
	d = rotate_point(a, t);
	_1.x = (int)((d.x - d.y) * (cos(0.523599)))  + fdf->x_offset;
	_1.y = (int)((d.x + d.y) * (0.5 * sin(0.523599)) - (d.z * 0.5 * 0.2)) + fdf->y_offset;
	drawline(fdf->img, _0, _1,  color(_0, _1));
}

static void	project_1(t_fdf *fdf, t_vector *map, t_vertex _0, t_vertex p)
{
	t_vector	*row;

	row = ((t_vector **)map->item)[p.y];
	if (p.x < row->len - 1)
	{
		p.data = ((t_data *)row->item)[p.x + 1];
		projection_right(fdf, _0, p);
	}
	if (p.y < map->len - 1)
	{
		row = ((t_vector **)map->item)[p.y + 1];
		p.data = ((t_data *)row->item)[p.x];
		projection_down(fdf, _0, p);
	}
}

static void	project_0(t_fdf *fdf, t_vector *row, t_vertex *_0, t_vertex p)
{
	t_rotate 	d;
	t_vertex	c;
	t_rotate	s;
	t_vertex	t;
	t_matrice a = (t_matrice){};

	p.data = ((t_data *)row->item)[p.x];

	rotate_x(fdf, &c);
	a.r11 = c.y * c.z;
	a.r12 = s.x * s.y * c.z - c.x * s.z;
	a.r13 = s.x * s.z + c.x * s.y * c.z;
	rotate_y(fdf, &c);
	a.r21 = c.y * s.z;
	a.r22 = c.x * c.z + s.x * s.y* s.z;
	a.r23 = c.x * s.y * s.z - s.x * c.z;
	rotate_z(fdf, &c);
	a.r31 = -s.y;
	a.r32 = s.x * c.y;
	a.r33 = c.x * c.y;

//	fdf->r = matrix_to_angle(a);
	t.x = (p.x * fdf->tile_size);
	t.y = (p.y * fdf->tile_size);
	t.z = -(p.data.z * (fdf->tile_size / 5));
//	d.x = c.y * (s.z * t.y + c.z * t.x) - s.y * t.z;
//	d.y = s.x * (c.y * t.z + s.y * (s.z * t.y + c.z * t.x)) + c.x * (c.z * t.y - s.z * t.x);
//	d.z = c.x * (c.y * t.z + s.y * (s.z * t.y + c.z * t.x)) - s.x * (c.z * t.y - s.z * t.x);
	d = rotate_point(a, t);
	_0->x = (int)((d.x - d.y) * (cos(0.523599)))  + fdf->x_offset;
	_0->y = (int)((d.x + d.y) * (0.5 * sin(0.523599)) - d.z * 0.5 * 0.2) + fdf->y_offset;
}

void	project(t_vector *map, t_fdf *fdf)
{
	t_vertex	p;
	t_vertex	_0;
	t_vector	*row;

	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	_0 = (t_vertex){};
	ft_memset(fdf->img->pixels, 0, sizeof(int) * \
	fdf->img->width * fdf->img->height);
	p.y = 0;
	while (p.y < map->len)
	{
		row = ((t_vector **)map->item)[p.y];
		p.x = 0;
		while (p.x < row->len)
		{
			project_0(fdf, row, &_0, p);
			project_1(fdf, map, _0, p);
			p.x++;
		}
		p.y++;
	}
}
