CC = cc
NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRC = ft_putnbr_fd.c\
	  ft_putendl_fd.c\
	  ft_putstr_fd.c\
	  ft_putchar_fd.c\
	  ft_striteri.c\
	  ft_strmapi.c\
	  ft_itoa.c\
	  ft_split.c\
	  ft_strtrim.c\
	  ft_strjoin.c\
	  ft_substr.c\
	  ft_strdup.c\
	  ft_calloc.c\
	  ft_atoi.c\
	  ft_strnstr.c\
	  ft_strlcat.c\
      	ft_strlcpy.c\
      	ft_strncmp.c\
      	ft_strrchr.c\
      	ft_strchr.c\
      	ft_toupper.c\
      	ft_tolower.c\
      	ft_isprint.c\
      	ft_isascii.c\
      	ft_isalnum.c\
      	ft_isdigit.c\
      	ft_isalpha.c\
	ft_strlen.c\
	  ft_memcmp.c\
	  ft_memchr.c\
	  ft_memmove.c\
	  ft_memcpy.c\
	  ft_bzero.c\
	  ft_memset.c\
	  ft_printf.c\
	  ft_printf_utils.c\
	  ft_print_hex.c\
	  ft_printf.c\
	  ft_print_unsigned.c\
	  ft_itoa.c\
	  ft_print_ptr.c\
	  get_next_line.c\
	  get_next_line_utils.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re so

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -c $(SRC)
	ar -rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf libft.so

re: fclean all

so:
	rm -rf libft.so
	$(CC) -fPIC $(FLAGS) -c $(SRC)
	$(CC) -shared -o libft.so $(OBJ)
