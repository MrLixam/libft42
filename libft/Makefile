SRCS = ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_striteri.c ft_strmapi.c ft_itoa.c ft_atoi.c ft_split.c ft_strtrim.c ft_strjoin.c ft_substr.c ft_calloc.c ft_strdup.c ft_strnstr.c ft_memcmp.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_memchr.c

BONUS_SRCS =  ft_lstadd_front.c ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

RM = rm -f

CC = gcc

AR = ar

AR_FLAGS = rc

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
	${AR} ${AR_FLAGS} ${NAME} ${OBJS}

all:	${NAME}

bonus: ${OBJS} ${BONUS_OBJS}
	${AR} ${AR_FLAGS} ${NAME} ${OBJS} ${BONUS_OBJS}

clean:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

so: 
	$(CC) -nostartfiles -fPIC $(FLAGS) $(SRCS) $(BONUS_SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus
