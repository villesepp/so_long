/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:21:13 by vseppane          #+#    #+#             */
/*   Updated: 2024/07/21 12:20:07 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*
 *	renders the map array to console (terminal)
*/
static void	console_map(t_data *game)
{
	int	i;

	i = 0;
	while (game->y > i)
	{
		ft_putstr_fd("  ", 1);
		ft_putstr_fd(game->arr[i], 1);
		i++;
	}
	ft_putstr_fd("\n", 1);
}

/*
 *	Prints relevant information to console (terminal)
*/
void	console_update(t_data *game)
{
	system("clear");
	console_message_header(game);
	console_map(game);
	if (game->collectible == 0)
		console_message_exit_open();
	if (game->pl_move_to == 'C')
		console_message_key_gold();
	if (game->pl_move_to == 'X')
		console_message_player_touch_guard();
}
