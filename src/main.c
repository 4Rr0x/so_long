/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:36:47 by jopedro-          #+#    #+#             */
/*   Updated: 2025/02/04 13:44:56 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_map	map;

	map = NULL;
	if (ac != 2)
		close_game(map, "Error\nInvalid number of arguments", 2);
	check_map(av[1]);
}
