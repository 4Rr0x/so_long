/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:35:52 by jopedro-          #+#    #+#             */
/*   Updated: 2025/02/26 12:08:37 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	valid_move(t_map *map, int x, int y)
{
	if (map->grid[x][y] == '1')
		return (0);
	if (map->grid[x][y] == 'E' && map->collect != 0)
		return (0);
	return (1);
}

void	action(t_map *map, int x, int y, void *img)
{
	if (map->grid[x][y] == 'C')
	{
		map->collect--;
		check_collects(map);
		map->grid[x][y] = '0';
	}
	if (map->grid[x][y] == 'E')
	{
		map->moves++;
		ft_printf("%i\n", map->moves);
		close_game(map, "YOU WON!! YOU RETRIVED ALL THE GOLD COINS\n", 1);
	}
	mlx_put_image_to_window(map->mlx, map->window, map->img->floor,
		map->player_y * 64, map->player_x * 64);
	mlx_put_image_to_window(map->mlx, map->window, img, y * 64, x * 64);
	map->player_x = x;
	map->player_y = y;
	map->moves++;
	ft_printf("%i\n", map->moves);
}
