SRCS_C := client.c ft_putstr_fd.c ft_strlen.c ft_isdigit.c ft_atoi.c

SRCS_S := server.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c

GCC = gcc

FLAGS = -c -Wall -Werror -Wextra

NAME = minitalk

OBJS_C = $(SRCS_C:.c=.o)

OBJS_S = $(SRCS_S:.c=.o)

all:	$(NAME)

$(NAME): server client

server: $(OBJS_S)
	$(GCC) $(FLAGS) $(SRCS_S)
	gcc -Wall -Wextra -Werror $(OBJS_S) -o server

client: $(OBJS_C)
	$(GCC) $(FLAGS) $(SRCS_C)
	gcc -Wall -Wextra -Werror $(OBJS_C) -o client	

clean:
	rm -rf $(OBJS_C) $(OBJS_S)

fclean: clean
	rm -rf server client

re: fclean all