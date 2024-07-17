/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_load_floor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:21:13 by vseppane          #+#    #+#             */
/*   Updated: 2024/07/16 18:42:33 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*
 *	Load floor
*/
void	textures_load_floor(t_data *game)
{	
	int	size;

	size = TEX_SIZE;
	game->tex_floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/floor1.xpm", &size, &size);
	if (!game->tex_floor)
		game_quit(game, -19, 2);
}
