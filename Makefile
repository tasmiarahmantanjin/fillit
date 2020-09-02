# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trahman <trahman@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/24 13:34:54 by wvaara            #+#    #+#              #
#    Updated: 2020/09/01 17:21:16 by wvaara           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAG =  -Wall -Wextra -Werror
SRCS = ft_read.c main.c ft_valid_file.c ft_count_hash.c \
	ft_check_line_break.c ft_save_tetri.c ft_solution.c ft_new_map.c \
	ft_print.c ft_clean_wrong_insert.c ft_free_map.c ft_input_to_solution.c \
	ft_free_old.c ft_free_str.c
OBJECTS = $(SRCS:.c=.o)
INCLUDES = Libft/
LIBRARY = Libft/libft.a
HEADER = fillit.h
LIBDIR = Libft

all: $(NAME)

$(NAME):
	@make -C $(LIBDIR)
	@gcc  $(FLAG) $(LIBRARY) $(SRCS) -I $(INCLUDES) -o $(NAME)
	@echo "\033[32mBuilt library.\033[0m"

$(SRCS): $(HEADER)

clean:
	@make clean -C  $(LIBDIR)
	@/bin/rm -f $(OBJECTS)
	@echo "\033[32mCleaned up object files.\033[0m"

fclean: clean
	@make fclean -C $(LIBDIR)
	@/bin/rm -f $(NAME)
	@echo "\033[32mCleaned up compiled files.\033[0m"

re: fclean all

.PHONY: all clean fclean re
