NAME = filler

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = filler.c get_next_line.c ft_place_x.c ft_place_o.c ft_get_info.c \
ft_checkplace_piece.c ft_get_map_and_piece.c player_2.c player_1.c

OBJ = $(SRC:.c=.o)

$(NAME) :
	make -C libft/ fclean && make -C libft/
	make -C visu/
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o filler

all : $(NAME)

clean :
	$(RM) $(OBJ)
	make -C visu/ clean
	make -C libft/ clean

fclean : clean
	make -C libft/ fclean
	make -C visu/ fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
