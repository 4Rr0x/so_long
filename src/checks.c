/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:57:33 by jopedro-          #+#    #+#             */
/*   Updated: 2025/02/26 12:08:49 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_collects(t_map *map)
{
	int	i;
	int	j;

	if (map->collect == 0)
	{
		i = 0;
		while (i < map->height)
		{
			j = 0;
			while (map->grid[i][j])
			{
				mlx_put_image_to_window(map->mlx, map->window,
					map->img->door_open, j * 64, i * 64);
				j++;
			}
			i++;
		}
	}
}
