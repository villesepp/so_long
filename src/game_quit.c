/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:01:54 by vseppane          #+#    #+#             */
/*   Updated: 2024/07/21 13:51:06 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*
 *	Free memory
*/
int	game_quit(t_data *game)
{
	free(game->map_file);
	map_free(game);
	if (game->pl == 1)
		console_message_quit();
	textures_free(game);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
}

/*
 *	Quit the game and display error message 
 *	- free memory depending on where the error occurred
*/
int	game_quit_error(t_data *game, int error, int error_stage)
{
	error_messages (error);
	if (error_stage == 1)
		free(game->map_file);
	if (error_stage == 2)
	{
		free(game->map_file);
		map_free(game);
	}
	if (error_stage == 3)
		game_quit(game);
	exit (0);
}
