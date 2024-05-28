/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:47:01 by vseppane          #+#    #+#             */
/*   Updated: 2024/05/28 14:50:43 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	errors1(int error);
static void	errors2(int error);

void	errors(int error)
{
	write(1, "Error: ", 7);

	if (error <= -1 && error >= -10)
		errors1(error);
	else if (error <= -11 && error >= -20)
		errors2(error);
	else
		write(1, "Undefined error. Cool!\n", 22);
}

static void	errors1(int error)
{
	if (error == -1)
		write(1, "Map is not a rectangle\n", 22);
	if (error == -2)
		write(1, "Map is not surrounded by walls\n", 22);
	else if (error == -3)
		write(1, "Map has no valid path to exit\n", 22);
	else if (error == -4)
		write(1, "Map was not found\n", 22);
	else if (error == -5)
		write(1, "Map has no exit\n", 22);
	else if (error == -6)
		write(1, "Map has no collectibles\n", 22);
	else if (error == -7)
		write(1, "Map has characters that are not allowed\n", 22);
	else if (error == -8)
		write(1, "Map has no player starting position\n", 22);
	else if (error == -9)
		write(1, "Map size is not valid\n", 22);
	else if (error == -10)
		write(1, "Error reading the file\n", 22);
	}

static void	errors2(int error)
{
	if (error == -11)
		write(1, "Invalid argument count\n", 22);
	else if (error == -12)
		write(1, "Too many exits\n", 22);
	else if (error == -13)
		write(1, "Too many starting positions\n", 22);
	else if (error == -14)
		write(1, "File name is not valid\n", 22);
	else if (error == -15)
		write(1, "Map name is too short to be valid\n", 22);
	else if (error == -16)
		write(1, "Error opening the file\n", 22);
	else if (error == -17)
		write(1, "\n", 22);
	else if (error == -18)
		write(1, "\n", 22);
	else if (error == -19)
		write(1, "\n", 22);
	else if (error == -20)
		write(1, "\n", 22);

}

