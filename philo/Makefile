NAME	= philo

OBJDIR	= obj/
SRCDIR	= src/

SRC		=	philo.c				\
			philo_time.c		\
			philo_routines.c	\
			philo_philos.c		\
			philo_input.c		\
			philo_forks.c 		\
			philo_actions.c		\
			philo_keychain.c	\

SRCOBJ	= $(patsubst %.c, $(OBJDIR)%.o, $(SRC))

CC		= cc
RMF		= rm -f
RMDIR	= rmdir
CFLAGS	= -Wall -Wextra -Werror

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -pthread -c $< -o $@

$(NAME): $(SRCOBJ)
	$(CC) $(SRCOBJ) -pthread $(CFLAGS) -o $(NAME)

clean:
	$(RMF) $(SRCOBJ)
	if [ -d "obj" ]; then $(RMDIR) $(OBJDIR); fi

fclean: clean
	$(RMF) $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re libmake
