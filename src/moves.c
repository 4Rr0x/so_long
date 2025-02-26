/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:21:17 by jopedro-          #+#    #+#             */
/*   Updated: 2025/02/24 11:46:47 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_up(t_map *map)
{
	if (valid_move(map, map->player_x - 1, map->player_y))
		action(map, map->player_x - 1, map->player_y, map->img->back);
}

void	move_down(t_map *map)
{
	if (valid_move(map, map->player_x + 1, map->player_y))
		action(map, map->player_x - 1, map->player_y, map->img->front);
}

void	move_right(t_map *map)
{
	if (valid_move(map, map->player_x, map->player_y + 1))
		action(map, map->player_x - 1, map->player_y, map->img->right);
}

void	move_left(t_map *map)
{
	if (valid_move(map, map->player_x, map->player_y - 1))
		action(map, map->player_x - 1, map->player_y, map->img->left);
}
