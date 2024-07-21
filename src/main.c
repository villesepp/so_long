/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:21:43 by vseppane          #+#    #+#             */
/*   Updated: 2024/07/17 18:37:56 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*
 *	get current time
 *	convert seconds to ms and nanoseconds to ms 
 */
static void	get_monotonic_time(t_data *game)
{
	struct timespec	ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);
	game->time = ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
}

/*
 *	Update time and trigger animations
*/
static int	update(t_data *game)
{
	get_monotonic_time(game);
	if (game->collectible == 0 && game->pl_on == 'E' && game->time % 5 < 1)
		render_gameover(game, 0);
	else if (game->pl < 1 && game->time % 5 < 1)
		render_gameover(game, 000255000000);
	else if (game->time % 5 < 1)
	{
		render_pieces_by_type(game, 'C');
		render_pieces_by_type(game, 'X');
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	game;

	ft_memset(&game, 0, sizeof(t_data));
	error_checks(argv[1], &game, argc);
	inits(&game);
	mlx_key_hook(game.win_ptr, key_inputs, &game);
	mlx_loop_hook(game.mlx_ptr, update, &game);
	mlx_hook(game.win_ptr, 17, 1L << 17, game_quit, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
