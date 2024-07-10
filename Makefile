# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aadenan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 12:53:21 by aadenan           #+#    #+#              #
#    Updated: 2024/07/10 13:06:01 by aadenan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc -g
CFLAGS := -Wall -Wextra -Werror

RED = \033[1;31m
GREEN = \033[1;32m
RESET = \033[0m

PROGRAM := philo

SRCS := philo.c parse_input.c data_init.c create_malloc.c create_lock.c \
	create_philo.c execute_dinner.c utils_one.c utils_two.c utils_three.c

OBJS := $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(PROGRAM)

clean:
	rm -f $(OBJS)
	$(RM) $(OBJS)

fclean: clean
	rm -f $(PROGRAM)
	@echo "$(RED)--- Program removed ---$(RESET)"

re: fclean all

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROGRAM)
	@echo "$(GREEN)--- Program created ---$(RESET)"

