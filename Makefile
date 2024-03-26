# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 11:24:26 by fcasaubo          #+#    #+#              #
#    Updated: 2024/03/11 15:54:10 by fcasaubo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		:=	push_swap
SRC_PATH	:=	src
LIBFT		:=	libft.a
LIBFT_PATH	:=	lib/libft/
OBJ_DIR		:=	obj
SOURCES		:=	main.c 				\
				algorithm.c			\
				execute_movement.c	\
				movements.c			\
				check_order.c		\
				parsing.c			\
				utils.c

OBJS		:=	$(SOURCES:%.c=$(OBJ_DIR)/%.o)
CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror -Iinclude

all: $(NAME)

$(NAME): $(OBJS)
	@clear
	@make -C $(LIBFT_PATH)
	@cp $(LIBFT_PATH)$(LIBFT) ./$(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@printf "Compiled"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_PATH)/%.c $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	@make -C $(LIBFT_PATH) clean
	@rm -fr $(OBJ_DIR)

fclean:
	@make -C $(LIBFT_PATH) fclean
	@rm -fr $(OBJ_DIR)
	@rm -f $(NAME)
	@rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re