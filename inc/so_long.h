/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:06:44 by jopedro-          #+#    #+#             */
/*   Updated: 2025/02/26 10:14:21 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/42_libft/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/42_libft/ft_printf/ft_printf.h"

# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_img
{
	void	*floor;
	void	*wall;
	void	*front;
	void	*back;
	void	*left;
	void	*right;
	void	*door_closed;
	void	*door_open;
	void	*collect;
}	t_img;

typedef struct s_map
{
	char	**grid;
	char	**grid_clone;
	int		moves;
	void	*mlx;
	void	*window;
	int		height;
	int		width;
	int		collect;
	char	*path;
	int		player;
	int		player_x;
	int		player_y;
	int		exit;
	t_img	*img;
}	t_map;

void	check_map(t_map	*map);
void	map_chars(t_map *map, int i, int j);
void	clone_grid(t_map *map);
void	map_stats(t_map *map);
void	create_window(t_map *map);
void	check_walls(t_map *map);
int		key_handler(int keycode, t_map *map);
int		valid_move(t_map *map, int x, int y);
void	action(t_map *map, int x, int y, void *img);
void	check_collects(t_map *map);
void	move_up(t_map *map);
void	move_down(t_map *map);
void	move_right(t_map *map);
void	move_left(t_map *map);
void	flood_fill(int x, int y, t_map *map);
void	close_game(t_map *map, char *str, int fd);
int		close_window(t_map *map);
t_map	*init_struct(void);
void	map_height(t_map *map);

#endif
