# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acami <acami@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/03 12:43:08 by acami             #+#    #+#              #
#    Updated: 2021/08/03 14:05:08 by acami            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all :
			@make -sC ./push_swap push_swap
			@make -sC ./checker checker

clean :
			@make -sC ./push_swap clean
			@make -sC ./checker clean

fclean :	
			@make -sC ./push_swap fclean
			@make -sC ./checker fclean

re :		
			@make -sC ./push_swap re
			@make -sC ./checker re

.PHONY : 		all clean fclean re