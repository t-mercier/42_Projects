/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   1_parse.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 21:07:55 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"



bool is_space(char c)
{
	return (c == 20);
}

//
//int	parse_line(int fd, t_map *map)
//{
//	char	**line;
//	size_t	i;
//	int		num;
//	int		color;
//
//	line = read_map(fd);
//	if (line == NULL)
//		return (1);
//	if (line[0] == NULL)
//		exit_message("fdf: empty line");
//	i = 0;
//	while (line[i])
//	{
//		if (map->column_count != 0 && i >= map->column_count)
//			exit_message("fdf: line is too long");
//		if (parse_num_color(line[i], &num, &color) < 0)
//			exit_message("fdf: invalid number");
//		add_point(&map->points, (t_map){.grid = {i, map->line_sum, num}, map->trace->point->color = color});
//		i++;
//	}
//	ft_split_free(line);
//	map->column_count = i;
//	return (0);
//}
//
//t_map	*parse_map(char *filename)
//{
//	int		fd;
//	t_map	*map;
//
//	map = init_map();
//	fd = open(filename, O_RDONLY);
//	if (fd < 0)
//	{
//		perror("fdf");
//		exit(EXIT_FAILURE);
//	}
//	while (1)
//	{
//		if (parse_line(fd, map))
//			break ;
//		map->row_count++;
//	}
//	return (map);
//}