/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:13:35 by jopedro-          #+#    #+#             */
/*   Updated: 2025/02/21 12:45:34 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key_handler(int keycode, t_map *map)
{
	if (keycode == XK_Up || keycode == 'w')
		move_up(map);
	else if (keycode == XK_Down || keycode == 's')
		move_down(map);
	else if (keycode == XK_Left || keycode == 'a')
		move_left(map);
	else if (keycode == XK_Right || keycode == 'd')
		move_right(map);
	else if (keycode == XK_Escape)
		close_game(map, "Closing the game, hope you had fun!\n", 1);
	return (0);
}

int	close_window(t_map *map)
{
	close_game(map, "Game closed by you\n", 1);
	return (0);
}
