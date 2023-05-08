NAME	= philosophers

OBJDIR	= obj/
SRCDIR	= src/

SRC		=	philosophers.c	\
			philo_utils.c

SRCOBJ	= $(patsubst %.c, $(OBJDIR)%.o, $(SRC))

CC		= cc
RM		= rm -f
RMDIR	= rmdir
CFLAGS	= -Wall -Wextra -Werror

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SRCOBJ)
	$(CC) $(SRCOBJ) $(CFLAGS) -o $(NAME)

clean: 
	$(RM) $(SRCOBJ)
	if [ -d "obj" ]; then rmdir obj; fi

fclean: clean
	$(RM) $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re libmake
