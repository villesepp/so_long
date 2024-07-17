/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_inits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:21:13 by vseppane          #+#    #+#             */
/*   Updated: 2024/07/17 12:59:00 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*
 *	Initialize MLX
*/
static void	mlx_init_ptr(t_data *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		free(game->mlx_ptr);
		game_quit(game, -18, 0);
	}
}

/*
 *	Initialize MLX window
*/
static void	mlx_init_window(t_data *game)
{
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->x * TEX_SIZE, game->y * TEX_SIZE, "so_long");
	if (!game->mlx_ptr)
	{
		free (game->mlx_ptr);
		game_quit(game, -18, 0);
	}
}

/* 
 *	init_values
 *  - sets default values for things
*/
void	init_values(t_data *game)
{
	game->x = -1;
	game->y = 0;
	game->collectible = 0;
	game->exit = 0;
	game->pl = 0;
	game->pl_on = '0';
	game->pl_move_dir = 1;
	game->moves = 0;
}

/*
 *	Initialize things that help with map creation, error checking etc.
*/
void	inits(t_data *game)
{
	map_create(game);
	map_check(game);
	console_update(game);
	mlx_init_ptr(game);
	textures_load(game);
	mlx_init_window(game);
	render_pieces(game);
	render_moves(game);
}
