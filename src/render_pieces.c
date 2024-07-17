/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pieces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:54:36 by vseppane          #+#    #+#             */
/*   Updated: 2024/07/16 18:39:40 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*
 *	Render wall pieces 'randomly'
*/
void	render_wall_random(t_data *game, int x, int y, int sum)
{
	if (sum % 5 == 1)
		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->tex_wall1, y * TEX_SIZE, x * TEX_SIZE);
	else if (sum % 6 == 2)
		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->tex_wall2, y * TEX_SIZE, x * TEX_SIZE);
	else if (sum % 7 == 3)
		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->tex_wall3, y * TEX_SIZE, x * TEX_SIZE);
	else
		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->tex_wall4, y * TEX_SIZE, x * TEX_SIZE);
}

/*
 *	Render collectible by time
*/
void	render_collectible_animation(t_data *game, int x, int y)
{
	int	loop_len;

	loop_len = 1000;
	if (game->time % loop_len < 50)
		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->tex_collectible2, y * TEX_SIZE, x * TEX_SIZE);
	else if (game->time % loop_len < 100)
		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->tex_collectible3, y * TEX_SIZE, x * TEX_SIZE);
	else if (game->time % loop_len < 150)
		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->tex_collectible4, y * TEX_SIZE, x * TEX_SIZE);
	else
		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->tex_collectible1, y * TEX_SIZE, x * TEX_SIZE);
}

/*
 *	Render player by move direction
*/
void	render_player(t_data *game, int x, int y)
{
	if (game->pl_move_dir == 1)
		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->tex_player1, y * TEX_SIZE, x * TEX_SIZE);
	if (game->pl_move_dir == 2)
		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->tex_player2, y * TEX_SIZE, x * TEX_SIZE);
	if (game->pl_move_dir == 3)
		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->tex_player3, y * TEX_SIZE, x * TEX_SIZE);
	if (game->pl_move_dir == 4)
		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->tex_player4, y * TEX_SIZE, x * TEX_SIZE);
}

/*
 *	Render enemy by time
*/
void	render_enemy_animation(t_data *game, int x, int y)
{
	int	loop_len;

	loop_len = 1000;
	if (game->time % loop_len < 333)
		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->tex_enemy1, y * TEX_SIZE, x * TEX_SIZE);
	else if (game->time % loop_len < 667)
		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->tex_enemy2, y * TEX_SIZE, x * TEX_SIZE);
	else
		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->tex_enemy3, y * TEX_SIZE, x * TEX_SIZE);
}
