
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trahman <trahman@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/24 13:34:54 by wvaara            #+#    #+#              #
#    Updated: 2020/08/11 14:39:28 by wvaara           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAG =  -Wall -Wextra -Werror
SRCS = ft_read.c main.c ft_valid_file.c ft_count_hash.c \
	ft_check_line_break.c ft_save_tetri.c ft_solution_tasmia.c ft_new_map.c \
	ft_print.c
OBJECTS = $(SRCS:.c=.o)
INCLUDES = Libft/includes
LIBRARY = Libft/libft.a
HEADER = fillit.h
LIBDIR = Libft/

all: $(NAME)

$(NAME):
	@make -C $(LIBDIR)
	@gcc $(FLAG) $(LIBRARY) $(SRCS) -I $(INCLUDES) -o $(NAME)
	@echo "\033[32mBuilt library.\033[0m"

$(SRCS): $(HEADER)

clean:
	@/bin/rm -f $(OBJECTS)
	@make clean -C  $(LIBDIR)
	@echo "\033[32mCleaned up object files.\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIBDIR)
	@echo "\033[32mCleaned up compiled files.\033[0m"

re: fclean all

.PHONY: all clean fclean re
