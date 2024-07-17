/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:40:14 by vseppane          #+#    #+#             */
/*   Updated: 2024/07/17 12:50:55 by vseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 64
# define TEX_SIZE 128

# include <time.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

typedef struct t_datas
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*map_file;
	char	**arr;
	int		fd;
	int		x;
	int		y;
	int		collectible;
	int		exit;
	int		moves;
	int		time;
	int		pl;
	int		pl_x;
	int		pl_y;
	int		pl_move_dir;
	char	pl_on;
	char	pl_move_to;
	void	*tex_wall1;
	void	*tex_wall2;
	void	*tex_wall3;
	void	*tex_wall4;
	void	*tex_floor;
	void	*tex_player1;
	void	*tex_player2;
	void	*tex_player3;
	void	*tex_player4;
	void	*tex_collectible1;
	void	*tex_collectible2;
	void	*tex_collectible3;
	void	*tex_collectible4;
	void	*tex_exit1;
	void	*tex_exit2;
	void	*tex_enemy1;
	void	*tex_enemy2;
	void	*tex_enemy3;
}	t_data;

void	error_messages(int error);
void	error_checks(char *map, t_data *game, int argc);

void	inits(t_data *game);
void	init_values(t_data *game);

int		game_quit(t_data *game, int error, int error_stage);
int		key_inputs(int code, t_data *game);
void	map_update(t_data *game, int x, int y);

void	map_check(t_data *game);
void	map_create(t_data *game);

void	map_free(t_data *game);
void	console_update(t_data *game);
void	console_message_quit(void);
void	console_message_exit_open(void);
void	console_message_header(t_data *game);
void	console_message_key_gold(void);
void	console_message_player_touch_guard(void);

void	piece_and_size_check(t_data *game);

void	textures_load(t_data *game);
void	textures_load_floor(t_data *game);
void	textures_load_wall(t_data *game);
void	textures_load_exit(t_data *game);
void	textures_load_player(t_data *game);
void	textures_load_enemy(t_data *game);
void	textures_load_collectible(t_data *game);

void	render_pieces(t_data *game);
void	render_pieces_by_type(t_data *game, char piece);
void	render_single_piece(t_data *game, int x, int y);
void	render_pieces_by_type(t_data *game, char piece);

void	render_enemy_animation(t_data *game, int x, int y);
void	render_wall_random(t_data *game, int x, int y, int sum);
void	render_collectible_animation(t_data *game, int x, int y);
void	render_player(t_data *game, int x, int y);
void	render_gameover(t_data *game, int color);
void	render_moves(t_data *game);

char	*get_next_line(int fd);

#endif
