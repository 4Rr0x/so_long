/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:57:33 by jopedro-          #+#    #+#             */
/*   Updated: 2025/02/24 11:46:15 by jopedro-         ###   ########.fr       */
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
		while (map->grid[i])
		{
			j = 0;
			while (map->grid[i][j])
			{
				if (map->grid[i][j] == 'E')
					mlx_put_image_to_window(map->mlx, map->window,
						map->img->door_open, i * 64, j * 64);
				j++;
			}
			i++;
		}
	}
}
