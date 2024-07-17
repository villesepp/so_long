/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:33:13 by vseppane          #+#    #+#             */
/*   Updated: 2024/07/17 13:04:19 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*
 *	Render moves inside the window
*/
void	render_moves(t_data *game)
{
	char	*moves;
	char	*moves_itoa;
	int		i;
	int		j;

	if (game->win_ptr == NULL)
		return ;
	j = 0;
	while (j++ < 15)
	{
		i = 0;
		while (i < 100)
			mlx_pixel_put(game->mlx_ptr, game->win_ptr, ++i, j, 00000000);
	}
	moves_itoa = ft_itoa(game->moves);
	moves = ft_strjoin("Moves: ", moves_itoa);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 10, 11111111, moves);
	free(moves_itoa);
	free(moves);
}

/*
 *	Check where the player is moving to
 *	- store what the player was standing on
 *	- if player is going to touch an enemy, decrement player count
 *	- if player is goint to touch a collectible, decrement collectible count
 *	- check if the exit texture should change
*/
static void	move_to_check(t_data *game)
{
	if (game->pl_move_to == '0')
		game->pl_on = '0';
	if (game->pl_move_to == 'E')
		game->pl_on = 'E';
	if (game->pl_move_to == 'X')
	{
		game->arr[game->pl_x][game->pl_y] = game->pl_on;
		console_update(game);
		game->pl -= 1;
	}
	if (game->pl_move_to == 'C')
	{
		game->pl_on = '0';
		game->collectible--;
		if (game->collectible == 0)
			render_pieces_by_type(game, 'E');
	}
}

/*
 *	Move the player
 *	- update the x and y coordinates
 *	- update player position in the array
 *	- render player
*/
static void	move_player(t_data *game, int x, int y)
{
	game->pl_x += x;
	game->pl_y += y;
	game->arr[game->pl_x][game->pl_y] = 'P';
	console_update(game);
	render_single_piece(game, game->pl_x, game->pl_y);
}

/*
 *	Update map by player movement
 *	Assign previous location by piece which the player was "on"
 *	Store the piece the player will move "on"
*/
void	map_update(t_data *game, int x, int y)
{
	game->moves++;
	game->arr[game->pl_x][game->pl_y] = game->pl_on;
	if (game->pl == 1)
		render_single_piece(game, game->pl_x, game->pl_y);
	render_moves(game);
	move_to_check(game);
	if (game->pl == 1)
		move_player(game, x, y);
}
