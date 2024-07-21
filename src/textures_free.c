/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:01:54 by vseppane          #+#    #+#             */
/*   Updated: 2024/07/21 13:50:56 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*
 *	Free individual textures from memory
*/
void	textures_free(t_data *game)
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
