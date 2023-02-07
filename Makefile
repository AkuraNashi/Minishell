# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcamilo- <lcamilo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 16:47:09 by lcamilo-          #+#    #+#              #
#    Updated: 2022/10/19 20:35:17 by lcamilo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ------------  COLORS  ------------------------------------------------------ #
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_ORANGE=\033[0;34m
COLOUR_END=\033[0m
COLOUR_YELLOW=\033[0;33m
COLOUR_CYAN=\033[0;36m

# ------------  PROJECT  ----------------------------------------------------- #
NAME		= Minishell

# ------------  DIRECTORIES  ------------------------------------------------- #
LIB				= libftprintfgnl
SRC_PATH		= ./
HEADERS			= includes
HEADERS_LIB		= libftprintfgnl/includes/libft.h
HEADERS_PRINTF	= libftprintfgnl/includes/ft_printf.h
HEADERS_GNL		= libftprintfgnl/includes/get_next_line_bonus.h

INC			= $(addprefix $HEADERS_LIB)

# ------------  FLAGS  ------------------------------------------------------- #
CFLAGS 		= -Wall -Wextra -Werror
CC			= @cc
RM			= rm -rf

# ------------  SOURCE FILES  ------------------------------------------------ #
SRC 		= 	main.c							\
				utils_lst.c						\
				utils_lst2.c

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS 		= $(addprefix $(SRC_PATH),$(SRC))
OBJS		= ${SRCS:.c=.o}

all: lib $(NAME)

lib:
			@echo "$(COLOUR_CYAN)Compilation libft..."
			make -C $(LIB)
			@echo "$(COLOUR_YELLOW)Deplacement du libft.a $(COLOUR_END)"
			@echo "$(COLOUR_GREEN)"cp ./libftprintfgnl/libft.a libft.a
			@echo "$(COLOUR_END)"

$(NAME): $(OBJS) ${HEADERS_LIB} ${HEADERS_GNL} ${HEADERS_PRINTF}
			@echo "$(COLOUR_CYAN)Compile..."
			$(CC) $(CFLAGS)  -I libftprintfgnl/includes -o $@ $(OBJS)  -L libftprintfgnl -lreadline -lft
			@echo "$(COLOUR_RED)Minishell ready. $(COLOUR_END)"

%.o: %.c
		${CC} $(CFLAGS) -I$(HEADERS) -I$(LIB) -c $< -o $@ -g3

clean:
			$(RM) ${OBJS}
			make fclean -C $(LIB)

fclean:		clean
			$(RM) $(NAME) *.a

re:			fclean all

.PHONY: re ignore fclean clean all $(LIBFT) $(NAME) $(PRINTF)