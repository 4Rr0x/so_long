/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:09:07 by jopedro-          #+#    #+#             */
/*   Updated: 2025/02/26 11:17:20 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	free_mlx(t_map *map)
{
	if (map->mlx)
	{
		if (map->img->back)
			mlx_destroy_image(map->mlx, map->img->back);
		if (map->img->front)
			mlx_destroy_image(map->mlx, map->img->front);
		if (map->img->right)
			mlx_destroy_image(map->mlx, map->img->right);
		if (map->img->left)
			mlx_destroy_image(map->mlx, map->img->left);
		if (map->img->wall)
			mlx_destroy_image(map->mlx, map->img->wall);
		if (map->img->floor)
			mlx_destroy_image(map->mlx, map->img->floor);
		if (map->img->door_open)
			mlx_destroy_image(map->mlx, map->img->door_open);
		if (map->img->door_closed)
			mlx_destroy_image(map->mlx, map->img->door_closed);
		if (map->window)
			mlx_destroy_window(map->mlx, map->window);
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
}

void	free_grid(char **grid, int height)
{
	int	i;

	i = 0;
	if (grid)
	{
		while (i < height)
			free (grid[i++]);
		free (grid);
	}
}

void	free_map(t_map *map)
{
	if (map)
	{
		if (map->grid)
			free_grid(map->grid, map->height);
		if (map->grid_clone)
			free_grid(map->grid_clone, map->height);
	}
}

void	close_game(t_map *map, char *msg, int fd)
{
	if (map)
		free_map(map);
	free_mlx(map);
	free(map);
	ft_putstr_fd(msg, fd);
	exit(1);
}
