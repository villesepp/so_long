/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:25:33 by vseppane          #+#    #+#             */
/*   Updated: 2024/07/21 12:43:46 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*
 *	checks if the map can fit on the school computers' 4K display
*/
static void	map_dimension_check(t_data *game)
{
	if (game->x > 30 || game->y > 16)
		game_quit_error(game, -20, 1);
}

/*
 *	checks if the map piece counts are valid for a proper map
*/
static void	piece_count_check(t_data *game)
{
	if (game->collectible < 1)
		game_quit_error(game, -6, 1);
	if (game->exit == 0)
		game_quit_error(game, -5, 1);
	if (game->exit > 1)
		game_quit_error(game, -12, 1);
	if (game->pl == 0)
		game_quit_error(game, -8, 1);
	if (game->pl > 1)
		game_quit_error(game, -13, 1);
}

/*
*	Checks the map file parameter
*	- the file name can fit a proper filename components
*	- if the name ends in .ber
*	- if the file can be opened for read only
*	- if the file can be read
*/
static void	map_file_name_check(char *map, t_data *game)
{
	int	len;

	len = ft_strlen(map);
	if (len < 5)
		game_quit_error(game, -15, 0);
	if (map[len - 1] == 'r' && map[len - 2] == 'e'
		&& map[len - 3] == 'b' && map[len - 4] == '.')
	{
		game->map_file = ft_strjoin("maps/", map);
	}
	else
		game_quit_error(game, -14, 0);
}

/*
 *	File open and read checks
*/
static void	map_file_read_open_check(t_data *game)
{
	int	fd;

	fd = open(game->map_file, O_RDONLY);
	if (fd == -1)
	{
		game_quit_error(game, -16, 0);
	}
	if (read (fd, NULL, 0) < 0)
	{
		close(fd);
		game_quit_error(game, -10, 0);
	}
	close(fd);
}

/*
 *	Verify that the map is good for playing
*/
void	error_checks(char *map, t_data *game, int argc)
{
	if (argc != 2)
		game_quit_error(game, -11, 0);
	map_file_name_check(map, game);
	map_file_read_open_check(game);
	textures_check(game);
	init_values(game);
	game->fd = open(game->map_file, O_RDONLY);
	piece_and_size_check(game);
	close(game->fd);
	map_dimension_check(game);
	piece_count_check(game);
}
