########################################################################
CC = gcc
OBJS = $(EX1:.c=.o)
CFLAGS = -Wall -Werror -Wextra -c
LIB = ar rcs
NAME = libft.a

EX1 = 	ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_substr.c\
		ft_strjoin
########################################################################
all: mklib

mklib: $(NAME)

$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS)

compile:
	$(CC) $(CFLAGS) $(EX1)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) 

re: fclean all