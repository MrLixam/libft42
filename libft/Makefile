# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 15:46:24 by lvincent          #+#    #+#              #
#    Updated: 2024/01/30 08:20:14 by lvincent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors !

GREEN = \033[0;32m

RED = \033[0;31m

RED_B = \033[1;31m

YELLOW = \033[1;33m

BLUE = \033[0;34m

RESET = \033[0m

#Sources relative to get_next_line
SRC =	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

#Sources relative to ft_printf
SRC	=	ft_printf/ft_printf.c ft_printf/ft_printf_utils1.c

#Sources relative file descriptor writing
SRC =	libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_putchar_fd.c

#Miscellaneous utilities
SRC =	libft/ft_itoa.c libft/ft_atoi.c libft/ft_split.c libft/ft_calloc.c libft/ft_memcmp.c
		
#Sources relative to single char operations
SRC =	libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c \
		libft/ft_isdigit.c libft/ft_isprint.c libft/ft_tolower.c libft/ft_toupper.c

#Sources relative to memory manipulation	
SRC	=	libft/ft_bzero.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_memchr.c

#Sources relative to string manipulation
SRC =	libft/ft_strchr.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strdup.c libft/ft_strnstr.c \
		libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strrchr.c libft/ft_substr.c libft/ft_strtrim.c \
		libft/ft_strjoin.c libft/ft_strmapi.c libft/ft_striteri.c

#Sources relative to chained lists
SRC =	libft/ft_lstadd_front.c libft/ft_lstnew.c libft/ft_lstsize.c libft/ft_lstlast.c \
		libft/ft_lstadd_back.c libft/ft_lstclear.c libft/ft_lstdelone.c libft/ft_lstiter.c libft/ft_lstmap.c

OBJ = ${SRC:.c=.o}

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

CC = clang

AR = ar

AR_FLAGS = rc

all : $(NAME)

.c.o:

	@echo -en "\\r\033[2K$(GREEN)Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJ)
	@echo -e "\n$(BLUE)Compiled object files for libft"
	@$(AR) $(AR_FLAGS) $(NAME) $(OBJ)
	@echo -e "$(YELLOW)Compiled libft!$(RESET)"
	
clean:
	@$(RM) $(OBJ)
	@echo -e "$(RED)removed object files from libft$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo -e "$(RED_B)Removed $(NAME) $(RESET)"

re: clean all

debug: CFLAGS += -g
debug: $(NAME)

.PHONY: all clean fclean re
