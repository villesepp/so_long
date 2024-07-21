/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:54:36 by vseppane          #+#    #+#             */
/*   Updated: 2024/07/17 18:07:19 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*
 *	Render all pieces
*/
void	render_pieces(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->x)
	{
		x = 0;
		while (x < game->y)
		{
			render_single_piece(game, x, y);
			x++;
		}
		y++;
	}
}

/*
 *	Render a single map piece at a coordinate
*/
void	render_single_piece(t_data *game, int x, int y)
{
	if (game->arr[x][y] == '0')
		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->tex_floor, y * TEX_SIZE, x * TEX_SIZE);
	if (game->arr[x][y] == '1')
		render_wall_random(game, x, y, x + y);
	if (game->arr[x][y] == 'C')
		render_collectible_animation(game, x, y);
	if (game->arr[x][y] == 'X')
		render_enemy_animation(game, x, y);
	if (game->arr[x][y] == 'E' && game->collectible > 0)
		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->tex_exit1, y * TEX_SIZE, x * TEX_SIZE);
	if (game->arr[x][y] == 'E' && game->collectible < 1)
		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->tex_exit2, y * TEX_SIZE, x * TEX_SIZE);
	if (game->arr[x][y] == 'P')
		render_player(game, x, y);
}

/*
 *	Render 'game over' curtain by color
*/
void	render_gameover(t_data *game, int color)
{
	static int	y = 0;
	int			i;

	y++;
	i = 0;
	while (i < game->x * TEX_SIZE)
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, ++i, y, color);
	if (y >= game->y * TEX_SIZE)
		game_quit(game);
}

/*
 *	Render all pieces that match a piece type
*/
void	render_pieces_by_type(t_data *game, char piece)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->x)
	{
		x = 0;
		while (x < game->y)
		{
			if (game->arr[x][y] == piece)
				render_single_piece(game, x, y);
			x++;
		}
		y++;
	}
}
