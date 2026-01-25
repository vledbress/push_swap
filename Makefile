# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/12 17:52:05 by vborysov          #+#    #+#              #
#    Updated: 2026/01/25 18:46:21 by vborysov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Пути
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

# Название бинарника
NAME = push_swap

# Исходники
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
	   normalize.c
	   
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

# Объектные файлы
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Инклуды
INCLUDES = -I$(INC_DIR)

# -------------------------
# Правила
# -------------------------

all: $(NAME)

# Компиляция бинарника
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Компиляция объектов
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Создание папки obj, если нет
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Очистка объектных файлов
clean:
	rm -rf $(OBJ_DIR)

# Полная очистка
fclean: clean
	rm -f $(NAME)

# Перекомпиляция
re: fclean all

.PHONY: all clean fclean re
