/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:38:17 by jopedro-          #+#    #+#             */
/*   Updated: 2025/02/27 13:45:41 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	load_img(t_map *map)
{
	int	size;

	size = 64;
	map->img->wall = mlx_xpm_file_to_image(map->mlx,
			"textures/wall.xpm", &size, &size);
	map->img->floor = mlx_xpm_file_to_image(map->mlx,
			"textures/floor.xpm", &size, &size);
	map->img->front = mlx_xpm_file_to_image(map->mlx,
			"textures/front.xpm", &size, &size);
	map->img->back = mlx_xpm_file_to_image(map->mlx,
			"textures/back.xpm", &size, &size);
	map->img->right = mlx_xpm_file_to_image(map->mlx,
			"textures/right.xpm", &size, &size);
	map->img->left = mlx_xpm_file_to_image(map->mlx,
			"textures/left.xpm", &size, &size);
	map->img->door_closed = mlx_xpm_file_to_image(map->mlx,
			"textures/door_closed.xpm", &size, &size);
	map->img->door_open = mlx_xpm_file_to_image(map->mlx,
			"textures/door_open.xpm", &size, &size);
	map->img->collect = mlx_xpm_file_to_image(map->mlx,
			"textures/collect.xpm", &size, &size);
	map->img->enemy = mlx_xpm_file_to_image(map->mlx,
			"textures/front_e.xpm", &size, &size);
}

void	put_img(char c, t_map *map, int i, int j)
{
	if (c == '0')
		mlx_put_image_to_window(map->mlx, map->window, map->img->floor,
			j * 64, i * 64);
	if (c == '1')
		mlx_put_image_to_window(map->mlx, map->window, map->img->wall,
			j * 64, i * 64);
	if (c == 'P')
		mlx_put_image_to_window(map->mlx, map->window, map->img->front,
			j * 64, i * 64);
	if (c == 'C')
		mlx_put_image_to_window(map->mlx, map->window, map->img->collect,
			j * 64, i * 64);
	if (c == 'E')
		mlx_put_image_to_window(map->mlx, map->window, map->img->door_closed,
			j * 64, i * 64);
	if (c == 'X')
		mlx_put_image_to_window(map->mlx, map->window, map->img->enemy,
			j * 64, i * 64);
}

void	load_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->grid[i][j] && map->grid[i][j] != '\n')
		{
			put_img(map->grid[i][j], map, i, j);
			j++;
		}
		i++;
	}
}

void	create_window(t_map *map)
{
	map->mlx = mlx_init();
	map->window = mlx_new_window(map->mlx, map->width * 64,
			(map->height * 64) + 48, "SO_LONG");
	load_img(map);
	load_map(map);
	render_moves(map);
	mlx_hook(map->window, KeyPress, KeyPressMask, key_handler, map);
	mlx_hook(map->window, DestroyNotify, 0, close_window, map);
	mlx_loop(map->mlx);
}
