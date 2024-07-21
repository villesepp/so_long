/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_load_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:21:13 by vseppane          #+#    #+#             */
/*   Updated: 2024/07/21 13:52:51 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*
 *	Load exit
*/
void	textures_load_exit(t_data *game)
{	
	int	size;

	size = TEX_SIZE;
	game->tex_exit1 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/exit1.xpm", &size, &size);
	game->tex_exit2 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/exit2.xpm", &size, &size);
}
