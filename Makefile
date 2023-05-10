NAME = philo

CC = gcc

RM = rm -rf

INCLUDE=-I

CFLAGS = -Wall -Wextra -Werror

SRCS = utils/all_free.c utils/create_thread.c utils/fst_utils.c utils/fst.c utils/ft_atoi.c utils/init_params.c utils/rtime.c utils/exit_free.c main.c 

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME) *.o

re: fclean all

.PHONY: all clean fclean re