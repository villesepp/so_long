/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:14:43 by vseppane          #+#    #+#             */
/*   Updated: 2024/07/16 18:36:43 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*
 *	Check the map after flood fill
 *	- if there are still exits or collectibles, the map design is not valid
*/
static int	map_flood_fill_check(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->x)
	{
		x = 0;
		while (x < game->y)
		{
			if (game->arr[x][y] == 'E' || game->arr[x][y] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

/*
 *	Flood fills the map from player starting position with 'walls'
*/
static void	map_flood_fill(t_data *game, int x, int y)
{
	if (game->arr[x][y] == '1')
		return ;
	game->arr[x][y] = '1';
	map_flood_fill(game, x + 1, y);
	map_flood_fill(game, x - 1, y);
	map_flood_fill(game, x, y + 1);
	map_flood_fill(game, x, y - 1);
}

/*
 *	Do a flood fill check on the map, free it and re-create it if no errors
 *	were found
*/
void	map_check(t_data *game)
{
	map_flood_fill(game, game->pl_x, game->pl_y);
	if (map_flood_fill_check(game))
		game_quit(game, -3, 2);
	map_free(game);
	map_create(game);
}
