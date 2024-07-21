#                _      _    _        
#  __ ____ _ _ _(_)__ _| |__| |___ ___
#  \ V / _` | '_| / _` | '_ \ / -_|_-<
#   \_/\__,_|_| |_\__,_|_.__/_\___/__/
#                                    

NAME		:=	so_long
CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror
MLX			:=	minilibx/Makefile.gen
LFT			:=	libft/libft.a
LIB			:=	-L ./libft -lft -L ./minilibx -lmlx -lXext -lX11 -lm -lbsd
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))

#
#   ___ ___ _  _ _ _ __ ___ ___
#  (_-</ _ \ || | '_/ _/ -_|_-<
#  /__/\___/\_,_|_| \__\___/__/
# 

SRC :=		src/main.c \
			src/error_messages.c \
			src/error_checks.c \
			src/key_inputs.c \
			src/get_next_line.c \
			src/map_read.c \
			src/map_create.c \
			src/map_update.c \
			src/map_check.c \
			src/game_quit.c \
			src/game_inits.c \
			src/render_pieces.c \
			src/render_utils.c \
			src/textures_check.c \
			src/textures_load.c \
			src/textures_load_wall.c \
			src/textures_load_floor.c \
			src/textures_load_exit.c \
			src/textures_load_player.c \
			src/textures_load_enemy.c \
			src/textures_load_collectible.c \
			src/textures_free.c \
			src/console.c \
			src/console_messages.c

#   _ __  __ _ _ __ ___
#  | '  \/ _` | '_ (_-<
#  |_|_|_\__,_| .__/__/
#             |_|      

mapsvalid :=	valid3.ber \ valid4.ber \ valid2.ber \ valid1.ber

mapsinvalid := ber \ invalid-lastlinetoolong.ber \ invalid-nostartingposition.ber \ invalid-badpiece.ber \ invalid-name.be \ invalid-notsurroundedbywalls1.ber \ invalid-empty.ber \ invalid-nocollectibles.ber \ invalid-notsurroundedbywalls2.ber \ invalid-emptylineend.ber \invalid-noexit.ber \ invalid-toowide.ber \ invalid-tootall.ber \ invalid-notsurroundedbywalls3.ber \ invalid-emptylinemid.ber \ invalid-nonrectangle.ber \ invalid-toosmall.ber \ invalid-emptylinestart.ber \ invalid-nopathtocollectible.ber \ invalid-twoexits.ber \ invalid-hole.ber \ invalid-nopathtoexit.ber \ invalid-twostartingpositions.ber

#   _                     _      
#  | |_ __ _ _ _ __ _ ___| |_ ___
#  |  _/ _` | '_/ _` / -_)  _(_-<
#   \__\__,_|_| \__, \___|\__/__/
#               |___/           

all:		$(MLX) $(LFT) obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(MLX):
			make -s -C mlx

$(LFT):		
			make -s -C libft

obj:
			mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(CFLAGS) -o $@ -c $<

clean:
			make -s $@ -C libft
			rm -rf $(OBJ) obj

fclean:		clean
			make -s $@ -C libft
			rm -rf $(NAME)

re:			fclean all

#        _           _ _    _      
#   _ __| |__ _ _  _| (_)__| |_ ___
#  | '_ \ / _` | || | | (_-<  _(_-<
#  | .__/_\__,_|\_, |_|_/__/\__/__/
#  |_|          |__/               

playlist:	all
			@for map in $(mapsvalid); do \
				./$(NAME) $$map; \
			done

faillist:	all
			@for map in $(mapsinvalid); do \
				./$(NAME) $$map; \
			done

.PHONY:		all clean fclean re playlist faillist vallist
