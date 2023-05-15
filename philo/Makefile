NAME	= philo

OBJDIR	= obj/
SRCDIR	= src/

SRC		=	philo.c			\
			philo_time.c	\
			philo_routines.c\
			philo_philos.c	\
			philo_input.c	\
			philo_forks.c 	\
			philo_actions.c	\


SRCOBJ	= $(patsubst %.c, $(OBJDIR)%.o, $(SRC))

CC		= cc
RMF		= rm -f
RMRF	= rm -rf
RMDIR	= rmdir
CFLAGS	= -Wall -Wextra -Werror

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SRCOBJ)
	$(CC) $(SRCOBJ) $(CFLAGS) -o $(NAME)

clean: 
	$(RMRF) $(OBJDIR)

fclean: clean
	$(RMF) $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re libmake
