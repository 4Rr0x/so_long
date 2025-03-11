/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:13:24 by jopedro-          #+#    #+#             */
/*   Updated: 2025/02/26 10:25:45 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_file(t_map	*map)
{
	if (ft_strcmp(ft_strrchr(map->path, '.'), ".ber") == 0
		&& ft_strlen(map->path))
		return ;
	close_game(map, "Error\nInvalid input file\n", 2);
}

void	map_stats(t_map	*map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->grid[i][j] && map->grid[i][j] != '\n')
		{
			map_chars(map, i, j);
			j++;
		}
		if (map->width != j && map->width != 0)
			close_game(map, "Error\nThe map must be a rectangle\n", 2);
		map->width = j;
		i++;
	}
}

void	fill_grid(t_map	*map)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(map->path, O_RDONLY);
	if (fd == -1)
		close_game(map, "Error\nError opening the file descriptor\n", 2);
	map->grid = malloc(sizeof(char *) * map->height);
	if (!map->grid)
		close_game(map, "Error\nError allocating memory for map grid\n", 2);
	line = get_next_line(fd);
	while (line && *line)
	{
		map->grid[i] = malloc(sizeof(char) * ft_strlen(line) + 1);
		if (!map->grid[i])
			close_game(map, "Error\nError allocating memory for map grid\n", 2);
		ft_strlcpy(map->grid[i], line, ft_strlen(line) + 1);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	check_contents(t_map *map)
{
	if (map->player != 1)
		close_game(map, "Error\nThe map must have only 1 player\n", 2);
	if (map->exit != 1)
		close_game(map, "Error\nThe map must have only 1 exit\n", 2);
	if (map->collect <= 0)
		close_game(map, "Error\nThe map must have at least 1 collectible\n", 2);
}

void	check_map(t_map	*map)
{
	check_file(map);
	map_height(map);
	fill_grid(map);
	map_stats(map);
	check_contents(map);
	clone_grid(map);
	check_walls(map);
}
