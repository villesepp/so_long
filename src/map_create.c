/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:31:29 by vseppane          #+#    #+#             */
/*   Updated: 2024/07/16 18:37:36 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*
 *	Free the map 'strings' line by line
*/
void	map_free(t_data *game)
{
	int	i;

	i = 0;
	if (!game->arr)
		return ;
	while (i < game->y)
	{
		free(game->arr[i]);
		game->arr[i] = NULL;
		i += 1;
	}
	free(game->arr);
	game->arr = NULL;
}

/*
 *	Make a map array
*/
void	map_create(t_data *game)
{
	int	i;

	i = 0;
	game->arr = (char **) malloc((game->y) * sizeof(char *));
	if (!game->arr)
		return ;
	game->fd = open(game->map_file, O_RDONLY);
	while (game->y > i)
	{
		game->arr[i] = get_next_line(game->fd);
		i++;
	}
	close(game->fd);
}
