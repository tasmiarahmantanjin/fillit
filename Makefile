# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/24 13:34:54 by wvaara            #+#    #+#              #
#    Updated: 2020/09/04 13:52:08 by wvaara           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAG =  -Wall -Wextra -Werror

SRCS = read_fillit_file.c check_line_break.c count_hash.c main.c \
	input_to_solution.c delete_dots.c solve_fillit.c fillit_algorithm.c \
	free_fillit.c finish_fillit.c free_fillit_str.c

OBJECTS = $(SRCS:.c=.o)

INCLUDES = Libft/

LIBRARY = Libft/libft.a

HEADER = fillit.h

LIBDIR = Libft

all: $(NAME)

$(NAME):
	@$(MAKE) -C $(LIBDIR)
	@gcc -c $(SRCS)
	@gcc  $(FLAG) $(LIBRARY) $(OBJECTS) -I $(INCLUDES) -o $(NAME)
	@echo "\033[32mBuilt library.\033[0m"

$(SRCS): $(HEADER)

clean:
	@$(MAKE) clean -C  $(LIBDIR)
	@/bin/rm -f $(OBJECTS)
	@echo "\033[32mCleaned up object files.\033[0m"

fclean: clean
	@$(MAKE) fclean -C $(LIBDIR)
	@/bin/rm -f $(NAME)
	@echo "\033[32mCleaned up compiled files.\033[0m"

re: fclean all

.PHONY: all clean fclean re
