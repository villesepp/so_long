/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:21:13 by vseppane          #+#    #+#             */
/*   Updated: 2024/07/21 13:48:21 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*
 *	Check if file exits
 *	- return 1 if yes, 0 if no
*/
static int	file_check(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		return (1);
	}
	return (0);
}

/*
 *	Check if texture files are found
*/
void	textures_check(t_data *game)
{	
	int			textures;
	int			i;
	const char	*texture_paths[] = {
		"textures/enemy1.xpm", "textures/enemy2.xpm", "textures/enemy3.xpm",
		"textures/exit1.xpm", "textures/exit2.xpm", "textures/wall1.xpm",
		"textures/wall2.xpm", "textures/wall3.xpm",	"textures/wall4.xpm",
		"textures/floor1.xpm", "textures/player1.xpm", "textures/player2.xpm",
		"textures/player3.xpm", "textures/player4.xpm",	"textures/key1.xpm",
		"textures/key2.xpm", "textures/key3.xpm", "textures/key4.xpm"
	};

	textures = sizeof(texture_paths) / sizeof(texture_paths[0]);
	i = 0;
	while (i < textures)
	{
		if (file_check(texture_paths[i]) == 0)
			game_quit_error(game, -21, 1);
		i++;
	}
}
