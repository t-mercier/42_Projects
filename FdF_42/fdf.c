/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   src.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 21:07:55 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include "libs/include/libft.h"

static int _min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
static int hexa_to_deci(char *hex)
{
	int y = 0;
	int n = 0;
	int x;
	size_t len;

	len = ft_strlen(hex) - 1;
	while (len--)
	{
		if (*(hex + len) >= '0' && *(hex + len) <= '9')
			x = *(hex + len) - '0';
		else
			x = *(hex + len) - 'A' + 10;
		n = (int) (n + x * pow(16, y));
	}
	return n;
}

t_vector *open_read_file(int fd)
{
	static char	**split;
	char		*line;
	int 		c;
	int 		n;
	t_vector	*map;
	t_vector	*row;
	t_vector	*color;
	map = vector_init(sizeof(t_vector *));
	while (1)
	{
		row = vector_init(sizeof(int));
		color = vector_init(sizeof(int));
		line = get_next_line(fd);
		if (!line)
			break ;
		split = ft_split(line, ' ');
		while (*split)
		{
			n = ft_atoi(*split++);
			vector_append(row, &n);
			if (ft_strchr(*split, 'x'))
				c = hexa_to_deci(ft_strchr(*split, 'x') + 1);
			else
				c = WHITE;
			vector_append(color, &c);
			vector_append(row, &color);
		}
		vector_append(map, &row);
		free(line);
	}
	close(fd);
	return (map);
}

void	set_camera(t_fdf *g, t_vector *y, t_vector *x)
{
	g->view.zoom = _min(WIDTH / x->len / 1.5, HEIGHT / y->len / 1.5);
	g->view.z_axis = 10;
}

void	conversion(t_pixel *p, int z)
{
	int x;
	int y;

	x = p->x;
	y = p->y;
	p->x = (x - y) * cos(0.523599);
	p->y = -z + (x + y) * sin(0.523599);
}

void trace(mlx_image_t *image, t_pixel p0, t_pixel p1, uint32_t color) {

	if (p0.x > image->width || p1.x > image->width ||
		p0.y > image->height || p1.y > image->height)
		return;
	int dx = abs(p1.x - p0.x);
	int sx = p0.x < p1.x ? 1 : -1;
	int dy = -abs(p1.y - p0.y);
	int sy = p0.y < p1.y ? 1 : -1;
	int error = dx + dy;

	while (1) {
		mlx_put_pixel(image, abs(p0.x), abs(p0.y), color);
		if (p0.x == p1.x && p0.y == p1.y)
			break;
		int e2 = 2 * error;
		if (e2 >= dy) {
			if (p0.x == p1.x)
				break;
			error += dy;
			p0.x += sx;
		}
		if (e2 <= dx) {
			if (p0.y == p1.y)
				break;
			error += dx;
			p0.y += sy;
		}
	}
}

t_pixel	line(t_pixel p, t_fdf *g, t_vector *x, t_vector *y)
{
	p.x *= (int)g->view.zoom;
	p.y *= (int)g->view.zoom;
	p.z *= (int)(g->view.zoom / g->view.z_axis);
	p.x -= (int)(((double)x->len * g->view.zoom) / 2);
	p.y -= (int)(((double)y->len * g->view.zoom) / 2);
	conversion(&p, p.z);
	p.x += WIDTH / 2 + g->view.x;
	p.y += HEIGHT / 2 + g->view.y;
	return (p);
}

void	projection(t_vector *map, t_fdf *m)
{
	t_pixel	p0;
	t_pixel	p1;
	t_pixel	p2;
	int		j;
	int		i;

	j = 0;
	ft_memset(&p0, 0, sizeof(t_pixel));
	ft_memset(&p1, 0, sizeof(t_pixel));
	while (j < map->len)
	{
		i = 0;
		t_vector *row = ((t_vector **)map->data)[j];
		t_vector *color = ((t_vector **)row->data)[i];
		while (i < row->len)
		{
			p0.z = ((int *)row->data)[i];
			if (i < row->len)
			{
				p1.x = i + 1;
				p1.y = j;
				p1.z = ((int *)row->data)[i + 1];
				p1.c = ((int *)color->data)[i + 1];
				trace(m->img, line(p0, m, map, row),
					 line(p1, m, map, row), p1.c);
			}
			if (j < map->len - 1)
			{
				p2.x = i;
				p2.y = j + 1;
				t_vector *nr = ((t_vector **)map->data)[j + 1];
				t_vector *nc = ((t_vector **)nr->data)[j + 1];
				p2.z = ((int *)nr->data)[i];
				p2.c = ((int *)nc->data)[i];
				trace(m->img, line(p0, m, map, row),
					 line(p2, m, map, row), p2.c);
			}
			i++;
		}
		j++;
	}
}

void error(void)
{
	char    *s;

	s = ft_strdup(mlx_strerror(mlx_errno));
	ft_putendl_fd(s, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void exit_message(char *s, int code)
{
	ft_putendl_fd(s, STDERR_FILENO);
	exit(code);
}

void	ft_key_hook(mlx_key_data_t keydata, void* param)
{
	(void) param;
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
		exit(EXIT_SUCCESS);
}

int32_t	main(int ac, char **av)
{
	t_vector	*map;
	t_vector	*row;
	t_fdf		m;
	int			fd;

	if (ac != 2)
		exit(EXIT_FAILURE);
	if (ft_strlen(av[1]) - 4 <= 0)
		error();
	ft_memset(&m.mlx, 0, sizeof(mlx_t *));
	ft_memset(&map, 0, sizeof(struct s_vector *));
	ft_memset(&row, 0, sizeof(struct s_vector *));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit_message("ERROR [ Empty map ]\n", 1);
	map = open_read_file(fd);
	m.mlx = mlx_init(2500, 1500, "FDF", true);
	if (!m.mlx)
		exit(EXIT_FAILURE);
	m.img = mlx_new_image(m.mlx, 2000, 1000);   // Creates a new image.
	mlx_image_to_window(m.mlx, m.img,  700, 100); // Draw the image at coordinate (0, 0).
	projection(map, &m);
	mlx_key_hook(m.mlx, &ft_key_hook, NULL);
	mlx_loop(m.mlx);
//	mlx_delete_image(mlx, img); // Once the application request an exit, cleanup
	mlx_terminate(m.mlx);
	return (EXIT_SUCCESS);
}

//	while (i.y0 < map->len)
//	{
//		row = ((t_vector **) map->data)[i.y0];
//		fprintf(stderr, "row y%d \n", i.y0);
//		while (i.x0 < row->len)
//		{
//			int zx = ((int *) row->data)[i.x0];
//			fprintf(stderr, "z[y%d][x%d] %d ", i.y0, i.x0, zx);
//			i.x0++;
//		}
//		fprintf(stderr, "\n");
//		i.y0++;
//	}

//	for (int j = 0; j < map->len; j++)
//	{
//		t_vector *row2 = ((t_vector **) map->data)[j];
//		for (int i = 0; i < row2->len; i++)
//		{
//			int zx = ((int *) row2->data)[i];
//			fprintf(stderr, "%d ", zx);
//		}
//		fprintf(stderr, "\n");
//	}
//	ft_memset(&p, 0, sizeof(t_map));