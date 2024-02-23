NAME = philo
FLAG = -Wall -Wextra -Werror -pthread -fsanitize=thread -g
SRC =	./check_and_init.c	\
		./creating.c 		\
		./destroy.c			\
		./main.c			\
		./philo_life.c		\
		./utils.c

all: $(NAME)

$(NAME):
	@gcc $(FLAG) -o $(NAME) $(SRC)
	@echo "\n\033[92m $@ built ✅\033[0m\n"

clean:
	@/bin/rm -f $(NAME)
	@echo "\n\033[36m object files removed 👋\033[0m\n"
fclean: clean

re: fclean all

.PHONY: all clean fclean re
