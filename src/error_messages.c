/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:47:01 by vseppane          #+#    #+#             */
/*   Updated: 2024/07/15 18:31:27 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	errors1(int error);
static void	errors2(int error);

void	error_messages(int error)
{
	ft_putstr_fd("Error\n", 1);
	if (error == 0)
	{
		ft_putstr_fd("No error logged.\n", 1);
		return ;
	}
	if (error <= -1 && error >= -10)
		errors1(error);
	else if (error <= -11 && error >= -20)
		errors2(error);
	else
		ft_putstr_fd("Undefined error. Cool!\n", 1);
}

static void	errors1(int error)
{
	if (error == -1)
		ft_putstr_fd("Map is not a rectangle\n", 1);
	if (error == -2)
		ft_putstr_fd("Map is not surrounded by walls\n", 1);
	else if (error == -3)
		ft_putstr_fd("Player can not get all collectibles and/or to exit\n", 1);
	else if (error == -4)
		ft_putstr_fd("Map was not found\n", 1);
	else if (error == -5)
		ft_putstr_fd("Map has no exit\n", 1);
	else if (error == -6)
		ft_putstr_fd("Map has no collectibles\n", 1);
	else if (error == -7)
		ft_putstr_fd("Map has characters that are not allowed\n", 1);
	else if (error == -8)
		ft_putstr_fd("Map has no player starting position\n", 1);
	else if (error == -9)
		ft_putstr_fd("Map size is not valid\n", 1);
	else if (error == -10)
		ft_putstr_fd("Error reading the file\n", 1);
}

static void	errors2(int error)
{
	if (error == -11)
		ft_putstr_fd("Invalid argument count\n", 1);
	else if (error == -12)
		ft_putstr_fd("Too many exits\n", 1);
	else if (error == -13)
		ft_putstr_fd("Too many starting positions\n", 1);
	else if (error == -14)
		ft_putstr_fd("File name is not valid\n", 1);
	else if (error == -15)
		ft_putstr_fd("Map name is too short to be valid\n", 1);
	else if (error == -16)
		ft_putstr_fd("Error opening the file\n", 1);
	else if (error == -17)
		ft_putstr_fd("Invalid map piece found\n", 1);
	else if (error == -18)
		ft_putstr_fd("MLX pointer error\n", 1);
	else if (error == -19)
		ft_putstr_fd("Error loading texture\n", 1);
	else if (error == -20)
		ft_putstr_fd("Map will not fit on a 4K display\n", 1);
}
