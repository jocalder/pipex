# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 21:26:05 by jocalder          #+#    #+#              #
#    Updated: 2025/01/13 19:58:05 by jocalder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

SRCS		= pipex.c pipex_utils.c

OBJS		= $(SRCS:.c=.o)

LIBFT_DIR	= ./libft

LIBFT_SRCS	= $(wildcard $(LIBFT_DIR)/*.c)

LIBFT_OBJS	= $(LIBFT_SRCS:.c=.o)

LIBFT		= $(LIBFT_DIR)/libft.a

CC 		= cc

FLAGS		= -Wall -Wextra -Werror

all: $(LIBFT) $(NAME)

$(LIBFT): $(LIBFT_OBJS)
	@echo  "\033[32mCreating libft library...\033[0m"
	ar rc $(LIBFT) $(LIBFT_OBJS)
	@ranlib $(LIBFT)

$(NAME): $(OBJS) $(LIBFT)
	@echo	"\033[34mCompiling...\033[0m"
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo	"\033[33mCleaning library...\033[0m"
	rm -f $(OBJS) $(LIBFT_OBJS)

fclean: clean
	@echo	"\033[31mCleaning executable and library...\033[0m"
	rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
