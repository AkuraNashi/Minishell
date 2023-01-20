# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 13:57:06 by aashara-          #+#    #+#              #
#    Updated: 2020/08/31 11:59:06 by aashara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------  COLORS  ------------------------------------------------------ #
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m
COLOUR_YELLOW=\033[0;33m
COLOUR_CYAN=\033[0;36m

# ------------  PROJECT  ----------------------------------------------------- #
NAME	=		libft.a

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_DIR	=		srcs
HDR_DIR	=		includes
OBJ_DIR	=		objs
LIBFT_DIR =		libft
FT_PRINTF_DIR =	ft_printf
GNL_DIR =		get_next_line

# ------------  SOURCE FILES  ------------------------------------------------ #

SRC_FLS	=		$(LIBFT_FLS)							\
				$(GNL_FLS)								\
				$(FT_PRINTF_FLS)

LIBFT_FLS = 	$(LIBFT_DIR)/ft_isalpha.c   			\
                $(LIBFT_DIR)/ft_isdigit.c   			\
               	$(LIBFT_DIR)/ft_isalnum.c   			\
               	$(LIBFT_DIR)/ft_isascii.c   			\
                $(LIBFT_DIR)/ft_isprint.c   			\
                $(LIBFT_DIR)/ft_strlen.c    			\
                $(LIBFT_DIR)/ft_memset.c    			\
                $(LIBFT_DIR)/ft_bzero.c     			\
                $(LIBFT_DIR)/ft_memcpy.c	 			\
                $(LIBFT_DIR)/ft_memmove.c   			\
                $(LIBFT_DIR)/ft_strlcpy.c   			\
                $(LIBFT_DIR)/ft_strlcat.c   			\
                $(LIBFT_DIR)/ft_toupper.c   			\
                $(LIBFT_DIR)/ft_tolower.c   			\
               	$(LIBFT_DIR)/ft_strchr.c    			\
                $(LIBFT_DIR)/ft_strrchr.c   			\
                $(LIBFT_DIR)/ft_strncmp.c   			\
                $(LIBFT_DIR)/ft_strncmp.c   			\
                $(LIBFT_DIR)/ft_memchr.c    			\
                $(LIBFT_DIR)/ft_memcmp.c				\
                $(LIBFT_DIR)/ft_strnstr.c   			\
                $(LIBFT_DIR)/ft_atoi.c      			\
               	$(LIBFT_DIR)/ft_calloc.c    			\
                $(LIBFT_DIR)/ft_strdup.c    			\
                $(LIBFT_DIR)/ft_substr.c    			\
                $(LIBFT_DIR)/ft_strjoin.c   			\
                $(LIBFT_DIR)/ft_strtrim.c   			\
                $(LIBFT_DIR)/ft_split.c	 				\
                $(LIBFT_DIR)/ft_itoa.c					\
                $(LIBFT_DIR)/ft_strmapi.c				\
                $(LIBFT_DIR)/ft_striteri.c				\
                $(LIBFT_DIR)/ft_putchar_fd.c			\
                $(LIBFT_DIR)/ft_putendl_fd.c			\
                $(LIBFT_DIR)/ft_putstr_fd.c 			\
                $(LIBFT_DIR)/ft_putnbr_fd.c				\
                $(LIBFT_DIR)/ft_lstnew_bonus.c		  	\
                $(LIBFT_DIR)/ft_lstadd_front_bonus.c	\
                $(LIBFT_DIR)/ft_lstsize_bonus.c			\
                $(LIBFT_DIR)/ft_lstlast_bonus.c			\
                $(LIBFT_DIR)/ft_lstadd_back_bonus.c		\
                $(LIBFT_DIR)/ft_lstdelone_bonus.c		\
                $(LIBFT_DIR)/ft_lstclear_bonus.c		\
                $(LIBFT_DIR)/ft_lstiter_bonus.c			\
                $(LIBFT_DIR)/ft_lstmap_bonus.c

FT_PRINTF_FLS = $(FT_PRINTF_DIR)/ft_printf.c			\
				$(FT_PRINTF_DIR)/ft_putchar.c			\
				$(FT_PRINTF_DIR)/ft_putnbr.c			\
				$(FT_PRINTF_DIR)/ft_putnbr_base.c		\
				$(FT_PRINTF_DIR)/ft_putstr.c			\
				$(FT_PRINTF_DIR)/ft_putunbr.c

GNL_FLS = 		$(GNL_DIR)/get_next_line_bonus.c		\
				$(GNL_DIR)/get_next_line_utils_bonus.c

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS	=		$(addprefix $(SRC_DIR)/, $(SRC_FLS))
OBJS	=		$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))
DEPS	=		$(OBJS:.o=.d)

# ------------  FLAGS  ------------------------------------------------------- #
CC		=		gcc
RM		=		rm -rf
CFLGS	=		-Wall -Werror -Wextra
IFLGS	=		-I $(HDR_DIR)
DFLGS	=		-MMD -MP -O1

# ------------  RULES  ------------------------------------------------------- #
.PHONY: all clean fclean re

all: $(NAME)

-include $(DEPS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@printf "$(COLOUR_CYAN)"
	$(CC) $(CFLGS) $(DFLGS) -c -o $@ $< $(IFLGS)

$(OBJ_DIR):
	@echo "$(COLOUR_YELLOW)Compilation des fichiers...$(COLOUR_END)"
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/$(LIBFT_DIR)
	mkdir -p $(OBJ_DIR)/$(FT_PRINTF_DIR)
	mkdir -p $(OBJ_DIR)/$(GNL_DIR)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	@echo "$(COLOUR_GREEN)Compilation terminé :)$(COLOUR_END)"


clean:
	@echo "$(COLOUR_RED)Supression des fichiers...$(COLOUR_END)"
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	@echo "$(COLOUR_GREEN)Suppresion terminé :)$(COLOUR_END)"

re: fclean all
