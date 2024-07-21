/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_load_collectible.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:21:13 by vseppane          #+#    #+#             */
/*   Updated: 2024/07/21 13:52:41 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*
 *	Load collectibles
*/
void	textures_load_collectible(t_data *game)
{
	int	size;

	size = TEX_SIZE;
	game->tex_collectible1 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/key1.xpm", &size, &size);
	game->tex_collectible2 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/key2.xpm", &size, &size);
	game->tex_collectible3 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/key3.xpm", &size, &size);
	game->tex_collectible4 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/key4.xpm", &size, &size);
}
