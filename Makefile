##
## EPITECH PROJECT, 2020
## my_world
## File description:
## Makefile
##

NAME	=	my_world

CC	=	gcc

RM	=	rm -f

SRCS	=	srcs/main.c \
			srcs/set_map.c \
			srcs/my_iso_point.c \
			srcs/scaling.c \
			srcs/map_move.c \
			srcs/change_height.c \
			srcs/height_average.c \
			srcs/update_coordinates.c \
			srcs/engine/engine.c \
			srcs/engine/mouse_pos.c \
			srcs/engine/buttons.c \
			srcs/stmngr/destroy.c \
			srcs/stmngr/init.c \
			srcs/stmngr/stmngr.c \
			srcs/stmngr/utils.c \
			srcs/scenes/init_game.c \
			srcs/scenes/init.c \
			srcs/scenes/menu.c \
			srcs/scenes/game.c \
			srcs/scenes/init_menu.c \
			srcs/scenes/check_buttons.c \
			srcs/scenes/ui.c \
			srcs/scenes/map_destroy.c \
			srcs/scenes/mouse_input.c \
			srcs/save.c \
			srcs/reset.c

%.o: %.c
			cc -o $@ -c $^ -g -W -Wall -Werror -Wextra

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror

LDFLAGS	=	-lm -Llib/my/ -lmy -Iinclude/ -g -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	lib $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LDFLAGS)

lib:
	cd lib/my/ && make all

clean:
	$(RM) $(OBJS)
	cd lib/my/ && make clean

fclean:	clean
	$(RM) $(NAME)
	cd lib/my/ && make fclean

re:	fclean all

.PHONY:	all lib clean fclean re
