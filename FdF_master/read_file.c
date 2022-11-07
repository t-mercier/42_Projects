
#include "../include/fdf.h"


//t_point	*create_points(int32_t x, int32_t y, int32_t z)
//{
//	t_point *point;
//
//	point = malloc(sizeof(struct s_point));
//	if (!point)
//		exit(EXIT_FAILURE);
//	point->z = z;
//	point->y = y;
//	point->y = x;
//	point->next = NULL;
//	return point;
//}
//
//void	add_point(t_map **map, t_point *new)
//{
//	if (!new)
//		return ;
//	if (!(*map))
//	{
//		new->next = NULL;
//		(*map)->point = new;
//		return ;
//	}
//	(*map)->point->next = new;
//	(*map)->point = new->next;
//	new->next = NULL;
//}

//void	set_points(char *line, t_map *map)
//{
//	int x = 0;
//	while (*line)
//	{
//		map->point = create_points(x, 0, 0);
//		map->point->z = (int)ft_strtol(*ft_split(line, ' '));
//		add_point(&map, map->point);
//		x++;
//		line++;
//	}
//}

//void	read_file(char *file, t_map *map)
//{
//	int fd = open(file, O_RDONLY);
//	char *line;
//	ft_memset(&map)
//	while (1)
//	{
//		line = get_next_line(fd);
//		if (line == NULL)
//			break ;
//		set_points(line, map);
//		map->point->y++;
//		if (map->point->x > map->width)
//			map->width = map->point->x;
//		map->point->y++;
//		free(line);
//	}
//	close(fd);
//}


//t_node	*create_map(t_fdf *src)
//{
//	t_list	*matrix_head;
//	t_list	*new_node;
//	int		*matrix_line;
//	char	*line;
//
//	line = get_next_line(src->map_fd);
//	if (!line)
//		exit(0);
//	src->cols = count_cols(line);
//	matrix_line = parse_line(line);
//	free(line);
//	new_node = ft_lstnew(matrix_line);
//	matrix_head = new_node;
//	while (matrix_line)
//	{
//		line = get_next_line(src->map_fd);
//		matrix_line = parse_line(line);
//		free(line);
//		new_node = ft_lstnew(matrix_line);
//		ft_lstadd_back(&matrix_head, new_node);
//	}
//	src->rows = ft_lstsize(matrix_head);
//	return (matrix_head);
//}