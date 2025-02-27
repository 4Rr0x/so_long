/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:36:47 by jopedro-          #+#    #+#             */
/*   Updated: 2025/02/24 18:09:09 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_map	*map;

	map = init_struct();
	if (ac != 2)
		close_game(map, "Error\nInvalid number of arguments\n", 2);
	map->path = av[1];
	check_map(map);
	create_window(map);
}
