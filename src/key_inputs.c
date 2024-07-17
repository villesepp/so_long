/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:46:44 by vseppane          #+#    #+#             */
/*   Updated: 2024/07/16 18:46:44 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*
 *	Check where the player is moving to
 *	- if there is a wall or the player is dead or the player is on exit and
 *	no collectibles are left, do not move
*/
static int	move_check(t_data *game, int x, int y)
{
	game->pl_move_to = game->arr[game->pl_x + x][game->pl_y + y];
	if (game->pl_move_to == '1' || game->pl < 1
		|| (game->pl_on == 'E' && game->collectible == 0))
		return (0);
	return (1);
}

/*
 *	Handle keyboard input
*/
int	key_inputs(int code, t_data *game)
{
	if (code == 65307 || code == 113)
		game_quit(game, 0, 0);
	if ((code == 65362 || code == 119) && (move_check(game, -1, 0)))
	{
		game->pl_move_dir = 1;
		map_update(game, -1, 0);
	}
	if ((code == 65364 || code == 115) && (move_check(game, 1, 0)))
	{
		game->pl_move_dir = 3;
		map_update(game, 1, 0);
	}
	if ((code == 65361 || code == 97) && (move_check(game, 0, -1)))
	{
		game->pl_move_dir = 4;
		map_update(game, 0, -1);
	}
	if ((code == 65363 || code == 100) && (move_check(game, 0, 1)))
	{
		game->pl_move_dir = 2;
		map_update(game, 0, 1);
	}
	return (1);
}
