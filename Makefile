##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NAME	=	palindrome

CC =		gcc
CFLAGS	=	-Werror -Wextra
CPPFLAGS += 	-I./include

SDIR	=	sources

SRC		=	$(SDIR)/init.c \
			$(SDIR)/invalid.c \
			$(SDIR)/npalindrome.c \
			$(SDIR)/palindrome.c \
			$(SDIR)/ppalindrome.c \
			$(SDIR)/parse_flag.c \
			$(SDIR)/tools.c \

MAIN	=	$(SDIR)/main.c

OBJ		=	$(SRC:.c=.o) \
			$(MAIN:.c=.o)


LIBFLAG	=	-L./lib -lmy

all: $(NAME)

$(NAME): $(OBJ)
	@make -C lib/my
	$(CC) -o  $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LIBFLAG)

clean:
	@make -C lib/my clean
	$(RM) $(OBJ)

fclean: clean
	@make -C lib/my fclean
	$(RM) $(NAME)

re: fclean $(NAME)

debug:	CFLAGS += -g

debug: ${OBJ}
	@make -C lib/my debug
	${CC} -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LIBFLAG)

.PHONY: all clean fclean re debug
