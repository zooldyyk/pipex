NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIB = ./libft
LIBFT = ./libft/libft.a
SRC = main.c \
		free.c \
		childs.c
OBJ =$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(MAKE) -C $(LIB)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean:
		@$(RM) $(OBJ)
		@$(RM) $(NAME)
		@$(MAKE) -C $(LIB) clean
 
fclean: clean
		@$(MAKE) -C ./libft fclean
		@$(RM) $(NAME)
re: fclean all

.PHONY: all re clean fclean