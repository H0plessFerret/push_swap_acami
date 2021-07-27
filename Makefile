# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acami <acami@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/03 16:05:13 by acami             #+#    #+#              #
#    Updated: 2021/07/27 16:31:22 by acami            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

HEADERS_DIR		=	./headers/

SRC_DIR			=	./srcs/
SRC_F			= 	double_circular_list.c \
ft_atol.c \
initializers.c \
parse_input.c \
utils.c \
error_handlers.c \
basic_operations.c \
operations_1.c \
operations_2.c \
sort.c \
sort_utils.c \
push_swap.c
SRCS			=	$(addprefix $(SRC_DIR), $(SRC_F))

OBJ_DIR			=	./objs/
OBJ_F			=	$(SRC_F:.c=.o)
OBJS			=	$(addprefix $(OBJ_DIR), $(OBJ_F))

DEBUG_F			=	main.c
D_SRCS			=	$(addprefix $(SRC_DIR), $(DEBUG_F))
D_OBJS			=	$(addprefix $(OBJ_DIR), $(DEBUG_F:.c=.o))

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g
INCLUDES		=	-I $(HEADERS_DIR)

# COLORS
RED 	= 	\033[0;31m
GREEN 	= 	\033[0;32m
BLUE	=	\033[0;34m
CYAN	=	\033[0;36m
RESET 	= 	\033[0m

debug	:		$(OBJ_DIR) $(OBJS) $(D_OBJS)
				@echo "$(NAME): $(GREEN)Creating $(NAME)$(RESET)"
				$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) $(OBJS) $(D_OBJS) -o $(NAME)
				@echo "$(NAME): $(GREEN)>>>>>>>>>> DONE <<<<<<<<<<$(RESET)"

$(NAME) :	 	$(OBJ_DIR) $(OBJS)
				@echo "$(NAME): $(GREEN)Creating $(NAME)$(RESET)"
				$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) $(OBJS) -o $(NAME)
				@echo "$(NAME): $(GREEN)>>>>>>>>>> DONE <<<<<<<<<<$(RESET)"

all : 			$(NAME)

bonus:			all

include $(wildcard $(OBJ_DIR)*.d)

$(OBJ_DIR) :
				@mkdir -p $(OBJ_DIR)
				@echo "$(NAME): $(GREEN)$(OBJ_DIR) was created$(RESET)"

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c		
				$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@ -MMD

clean :
				@echo "$(NAME): $(BLUE)Deleting $(OBJ_DIR)$(RESET)"
				@rm -rf $(OBJ_DIR)

fclean :		clean
				@echo "$(NAME): $(CYAN)Deleting $(NAME)$(RESET)"
				@rm -f $(NAME)

re :			fclean all

.PHONY : 		all clean fclean re bonus