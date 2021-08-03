# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acami <acami@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/03 12:46:16 by acami             #+#    #+#              #
#    Updated: 2021/08/03 18:21:06 by acami            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	checker

HEADERS_DIR		=	./headers/

SRC_DIR			=	./srcs/
GNL_DIR			=	./srcs/get_next_line/
STACK_DIR		=	./srcs/stack_operations/
UTILS_DIR		=	./srcs/utils/

SRC_F			= 	checker.c \
do_actions.c \
double_circular_list.c \
parse_input.c \
read_actions.c

GNL_F			=	get_next_line.c \
get_next_line_utils.c

STACK_F			=	basic_operations.c \
operations_1.c \
operations_2.c \
operations_3.c

UTILS_F			=	error_handlers.c \
ft_atol.c \
initializers.c \
str_utils.c \
utils.c

SRCS			=	$(addprefix $(SRC_DIR), $(SRC_F))
SRCS			+=	$(addprefix $(GNL_DIR), $(GNL_F))
SRCS			+=	$(addprefix $(STACK_DIR), $(STACK_F))
SRCS			+=	$(addprefix $(UTILS_DIR), $(UTILS_F))

SRC_SUBDIRS		=	. get_next_line/ stack_operations/ utils/
OBJ_DIR			=	./objs/
OBJ_DIRS		=	$(addprefix $(OBJ_DIR)/, $(SRC_SUBDIRS))

OBJS			=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g
INCLUDES		=	-I $(HEADERS_DIR)

# COLORS
RED 	= 	\033[0;31m
GREEN 	= 	\033[0;32m
BLUE	=	\033[0;34m
CYAN	=	\033[0;36m
RESET 	= 	\033[0m

all : 			$(NAME)

$(NAME) :	 	$(OBJS)
				@echo "$(NAME): $(GREEN)Creating $(NAME)$(RESET)"
				$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
				@echo "$(NAME): $(GREEN)>>>>>>>>>> DONE <<<<<<<<<<$(RESET)"

bonus:			all

include $(wildcard $(OBJ_DIR)*.d)

$(OBJ_DIRS) :
				@mkdir -p $@
				@echo "$(NAME): $(GREEN)$@ was created$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIRS)
				$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@ -MMD

clean :
				@echo "$(NAME): $(BLUE)Deleting $(OBJ_DIR)$(RESET)"
				@rm -rf $(OBJ_DIR)

fclean :		clean
				@echo "$(NAME): $(CYAN)Deleting $(NAME)$(RESET)"
				@rm -f $(NAME)

re :			fclean all

.PHONY : 		all clean fclean re bonus