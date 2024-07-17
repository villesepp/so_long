/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console_messages.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:21:13 by vseppane          #+#    #+#             */
/*   Updated: 2024/07/16 18:44:39 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*
 *	Header message
*/
void	console_message_header(t_data *game)
{
	ft_putstr_fd("\x1B[96m", 1);
	ft_putstr_fd("  _____        _                  ___ ____\n", 1);
	ft_putstr_fd(" |   __|___   | |___ ___ ___     |_  |    \\ \n", 1);
	ft_putstr_fd(" |__   | . |  | | . |   | . |_   |_  |  |  |\n", 1);
	ft_putstr_fd(" |_____|___|  |_|___|_|_|_  | |  |___|____/\n", 1);
	ft_putstr_fd("                        |___|_|\n\n", 1);
	ft_putstr_fd("\x1B[0m", 1);
	ft_putstr_fd(" You are an Allied spy William \"B.J.\" Blazkowicz.\n", 1);
	ft_putstr_fd(" Your goal is to escape from the Nazi German prison\n", 1);
	ft_putstr_fd("            Castle Wolfenstein. Good luck! \n\n", 1);
	ft_putstr_fd("   Map name: ", 1);
	ft_putstr_fd(game->map_file, 1);
	ft_putstr_fd("   Moves: ", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd("\n\n", 1);
}

/*
 *	Message when a key is picked up
*/
void	console_message_key_gold(void)
{
	ft_putstr_fd("\x1B[93m", 1);
	ft_putstr_fd("            You got a golden key!\n\n", 1);
	ft_putstr_fd("\x1B[0m", 1);
}

/*
 *	Message when exit is open
*/
void	console_message_exit_open(void)
{
	ft_putstr_fd("\x1B[92m", 1);
	ft_putstr_fd("            The exit is now open!\n\n", 1);
	ft_putstr_fd("\x1B[0m", 1);
}

/*
 *	Message when the game was quit
*/
void	console_message_quit(void)
{
	ft_putstr_fd("\x1B[96m", 1);
	ft_putstr_fd("     So long and thanks for all the keys!\n\n", 1);
	ft_putstr_fd("\x1B[0m", 1);
}

/*
 *	Message when the player touched an enemy
*/
void	console_message_player_touch_guard(void)
{
	ft_putstr_fd("\x1B[31m", 1);
	ft_putstr_fd("   You woke up the sleeping guard! Game over!\n\n", 1);
	ft_putstr_fd("\x1B[0m", 1);
}
