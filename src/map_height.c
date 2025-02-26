/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:10:01 by jopedro-          #+#    #+#             */
/*   Updated: 2025/02/26 10:13:24 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	map_height(t_map *map)
{
	int		lines;
	char	*line;
	int		fd;

	lines = 0;
	fd = open(map->path, O_RDONLY);
	if (fd == -1)
		close_game(map, "Error\nError opening map file\n", 2);
	line = get_next_line(fd);
	while (line && *line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	map->height = lines;
	close(fd);
}
