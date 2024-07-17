/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_load_player.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:21:13 by vseppane          #+#    #+#             */
/*   Updated: 2024/07/16 18:42:48 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*
 *	Load player
*/
void	textures_load_player(t_data *game)
{	
	int	size;

	size = TEX_SIZE;
	game->tex_player1 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/player1.xpm", &size, &size);
	if (!game->tex_player1)
		game_quit(game, -19, 2);
	game->tex_player2 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/player2.xpm", &size, &size);
	if (!game->tex_player2)
		game_quit(game, -19, 2);
	game->tex_player3 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/player3.xpm", &size, &size);
	if (!game->tex_player3)
		game_quit(game, -19, 2);
	game->tex_player4 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/player4.xpm", &size, &size);
	if (!game->tex_player4)
		game_quit(game, -19, 2);
}
