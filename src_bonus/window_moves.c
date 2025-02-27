/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:39:04 by jopedro-          #+#    #+#             */
/*   Updated: 2025/02/27 13:45:23 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	render_moves(t_map *map)
{
	char	*moves;
	int		len;

	moves = ft_itoa(map->moves);
	moves = ft_strjoin("Moves : ", moves);
	len = ft_strlen(moves) * 7;
	if (!map->img->moves)
		map->img->moves = mlx_new_image(map->mlx, map->width * 64, 48);
	mlx_put_image_to_window(map->mlx, map->window, map->img->moves, 0,
		map->height * 64);
	mlx_string_put(map->mlx, map->window, (map->width * 64 / 2)
		- (len / 2), map->height * 64 + 26, 0xFFFFFF, moves);
	free(moves);
}
