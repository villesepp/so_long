/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:01:54 by vseppane          #+#    #+#             */
/*   Updated: 2024/07/16 18:44:02 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*
 *	Free individual textures from memory
*/
static void	free_textures(t_data *game)
{
	mlx_destroy_image(game->mlx_ptr, game->tex_floor);
	mlx_destroy_image(game->mlx_ptr, game->tex_player1);
	mlx_destroy_image(game->mlx_ptr, game->tex_player2);
	mlx_destroy_image(game->mlx_ptr, game->tex_player3);
	mlx_destroy_image(game->mlx_ptr, game->tex_player4);
	mlx_destroy_image(game->mlx_ptr, game->tex_exit1);
	mlx_destroy_image(game->mlx_ptr, game->tex_exit2);
	mlx_destroy_image(game->mlx_ptr, game->tex_wall1);
	mlx_destroy_image(game->mlx_ptr, game->tex_wall2);
	mlx_destroy_image(game->mlx_ptr, game->tex_wall3);
	mlx_destroy_image(game->mlx_ptr, game->tex_wall4);
	mlx_destroy_image(game->mlx_ptr, game->tex_collectible1);
	mlx_destroy_image(game->mlx_ptr, game->tex_collectible2);
	mlx_destroy_image(game->mlx_ptr, game->tex_collectible3);
	mlx_destroy_image(game->mlx_ptr, game->tex_collectible4);
	mlx_destroy_image(game->mlx_ptr, game->tex_enemy1);
	mlx_destroy_image(game->mlx_ptr, game->tex_enemy2);
	mlx_destroy_image(game->mlx_ptr, game->tex_enemy3);
}

/*
 *	Free memory
*/
static void	game_quit_success(t_data *game)
{
	free(game->map_file);
	map_free(game);
	if (game->pl == 1)
		console_message_quit();
	free_textures(game);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
}

/*
 *	Quit the game and display error message (if any)
 *	- free memory depending on where the error occurred
*/
int	game_quit(t_data *game, int error, int error_stage)
{
	if (error == 0)
		game_quit_success(game);
	error_messages (error);
	if (error_stage == 1)
		free(game->map_file);
	if (error_stage == 2)
	{
		free(game->map_file);
		map_free(game);
	}
	exit (0);
}
