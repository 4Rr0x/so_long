/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:07:00 by jopedro-          #+#    #+#             */
/*   Updated: 2025/02/24 12:01:06 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	map_char(t_map *map, int i, int j)
{
	if (map->grid[i][j] == 'P')
	{
		map->player++;
		map->player_x = i;
		map->player_y = j;
	}
	else if (map->grid[i][j] == 'C')
		map->collect++;
	else if (map->grid[i][j] == 'E')
		map->exit++;
	else if (map->grid[i][j] != '0' && map->grid[i][j] != '1')
		close_game(map, "Error\nUknown character\n", 2);
}

void	flood_fill(int x, int y, t_map *map)
{
	if (map->grid_clone[x][y] == '1' || map->grid_clone[x][y] == 'F')
		return ;
	else if (map->grid_clone[x][y] == 'E')
		map->exit--;
	else if (map->grid_clone[x][y] == 'C')
		map->collect--;
	map->grid_clone[x][y] = 'F';
	if (x > 0)
		flood_fill(x - 1, y, map);
	if (x < map->height - 1)
		flood_fill(x + 1, y, map);
	if (y > 0)
		flood_fill(x, y - 1, map);
	if (y < map->width - 1)
		flood_fill(x, y + 1, map);
}

void	validate_fill(t_map *map)
{
	if (map->player != 0)
		close_game(map, "Error\nThe map must have only 1 player\n", 2);
	if (map->exit != 0)
		close_game(map, "Error\nThe map must have only 1 exit\n", 2);
	if (map->collect != 0)
		close_game(map, "Error\nThe map must have at least 1 collectible\n", 2);
}

void	clone_grid(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	map->grid_clone = malloc(sizeof(char *) * map->height);
	if (!map->grid_clone)
		close_game(map, "Error\nFailed to allocate memory for grid clone\n", 2);
	while (map->grid[i])
	{
		j = 0;
		map->grid_clone[i] = malloc(sizeof(char *) * map->width);
		if (map->grid_clone)
			close_game(map, "Error\nFailed to allocate memory for grid clone\n",
				2);
		while (map->grid[i][j])
		{
			map->grid_clone[i][j] = map->grid[i][j];
			j++;
		}
		i++;
	}
	flood_fill(map->player_x, map->player_y, map);
	validate_fill(map);
	map_stats(map);
}

void	check_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
			close_game(map, "Error\nThe map isn't enclosed in walls!\n", 2);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
			close_game(map, "Error\nThe map isn't enclosed in walls!\n", 2);
		i++;
	}
}
