/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_load_wall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:21:13 by vseppane          #+#    #+#             */
/*   Updated: 2024/07/21 13:53:31 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*
 *	Load wall
*/
void	textures_load_wall(t_data *game)
{	
	int	size;

	size = TEX_SIZE;
	game->tex_wall1 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/wall1.xpm", &size, &size);
	game->tex_wall2 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/wall2.xpm", &size, &size);
	game->tex_wall3 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/wall3.xpm", &size, &size);
	game->tex_wall4 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/wall4.xpm", &size, &size);
}
