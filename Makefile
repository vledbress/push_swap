# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/12 17:52:05 by vborysov          #+#    #+#              #
#    Updated: 2026/02/05 01:03:58 by vborysov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror


SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc


NAME = push_swap
LIBFT = libft/libft.a

SRCS = main.c \
       io.c \
	   node.c \
	   stack_basic.c \
	   stack_operations_1.c \
	   stack_operations_2.c \
	   error.c \
	   atol.c \
	   binary.c \
	   swap.c \
	   sort.c \
	   stack_io.c \
	   sort_small.c \
	   sort_move_b.c \
	   sort_move_a.c \
	   stack_init.c \
	   
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))


OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


INCLUDES = -I$(INC_DIR)


all: $(NAME)


$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)


clean:
	make -C libft clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
