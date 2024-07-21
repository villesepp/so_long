/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:07:32 by vseppane          #+#    #+#             */
/*   Updated: 2024/07/17 17:56:33 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*
 *		checks for walls in a line
 *		- return 1 if all walls
 *		- return 2 if left and right are walls
 *		- return 0 in other case, which means it's not a valid line
*/
static int	map_outer_walls_check(char *line)
{
	int	i;
	int	width;

	width = ft_strlen(line);
	if (line[width - 1] == '\n')
		width--;
	i = 0;
	while (line[i] == '1' && i <= width)
		i++;
	if (i == width)
		return (1);
	if (line[0] == '1' && line[width - 1] == '1')
		return (2);
	return (0);
}

/*
 *		checks if the map piece is valid and increments counts
 *		- throws error if an unexpected char is found
 *		- stores player position
*/
static void	piece_add(char c, t_data *game, int x, char *line)
{
	if (c == 'C')
		game->collectible++;
	if (c == 'E')
		game->exit++;
	if (c == 'P')
	{
		game->pl++;
		game->pl_y = x;
		game->pl_x = game->y;
	}
	if (c == '1' || c == 'C' || c == 'E' || c == 'P' || c == '0' || c == '\n'
		|| c == 'X')
		return ;
	free (line);
	game_quit_error(game, -17, 1);
}

/*
 *		checks if the line is valid
 *		- if the newly measured line is the same as the first
 * 		- if the measuring does not match, free the line and throw error
 *		- if the first and last line is all walls
 *		- if the mid line begins and ends with a wall piece
 *		- returns code for wall type, 0 is invalid, 1 is first/last, 2 is mid
*/
static int	line_check(t_data *game, char *line)
{
	int	width;
	int	walls;

	width = ft_strlen(line) - 1;
	if (game->x != -1)
	{
		if (width != game->x)
		{
			free(line);
			game_quit_error(game, -1, 1);
		}
	}
	if (game->x == -1)
		game->x = width;
	game->y++;
	walls = map_outer_walls_check(line);
	if ((game->y == 1 && walls != 1) || (game->y > 1 && walls == 0))
	{
		free (line);
		game_quit_error(game, -2, 1);
	}
	return (walls);
}

int	lastline_check(t_data *game, char *line, int lastline)
{
	if (line == NULL && lastline != 1)
	{
		free(line);
		game_quit_error(game, -2, 1);
	}
	if (line == NULL && lastline == 1)
	{
		free(line);
		return (1);
	}
	return (0);
}

/*
 *		checks if there are only valid pieces and the line widths are consistent
 *		- read a line
 *		- compare to previous line size
 *		- check pieces individually
 *		- if \n is found as a remainder, end of file was reached
*/
void	piece_and_size_check(t_data *game)
{
	char	*line;
	size_t	i;
	int		lastline;

	lastline = 0;
	while (1)
	{
		line = get_next_line(game->fd);
		if (lastline_check(game, line, lastline))
			break ;
		i = 0;
		while (ft_strlen(line) > i)
		{
			piece_add(line[i], game, i, line);
			i++;
		}
		lastline = line_check(game, line);
		free(line);
	}
}
