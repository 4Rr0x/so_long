/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:56:46 by jopedro-          #+#    #+#             */
/*   Updated: 2025/02/24 18:07:18 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_img	*init_struct_img(t_map *map)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		close_game(map, "Error\nError initializing images\n", 2);
	img->door_closed = NULL;
	img->door_open = NULL;
	img->back = NULL;
	img->collect = NULL;
	img->floor = NULL;
	img->front = NULL;
	img->left = NULL;
	img->right = NULL;
	img->wall = NULL;
	return (img);
}

t_map	*init_struct(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		close_game(map, "Error\nError initializing game\n", 2);
	map->img = init_struct_img(map);
	map->collect = 0;
	map->exit = 0;
	map->grid = NULL;
	map->grid_clone = NULL;
	map->height = 0;
	map->mlx = NULL;
	map->moves = 0;
	map->path = NULL;
	map->player = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->width = 0;
	return (map);
}

