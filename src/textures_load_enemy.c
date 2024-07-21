/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_load_enemy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:21:13 by vseppane          #+#    #+#             */
/*   Updated: 2024/07/21 13:53:07 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*
 *	Load enemy
*/
void	textures_load_enemy(t_data *game)
{	
	int	size;

	size = TEX_SIZE;
	game->tex_enemy1 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/enemy1.xpm", &size, &size);
	game->tex_enemy2 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/enemy2.xpm", &size, &size);
	game->tex_enemy3 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/enemy3.xpm", &size, &size);
}
