# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocalder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 21:26:05 by jocalder          #+#    #+#              #
#    Updated: 2025/01/03 19:53:58 by jocalder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex.program

SRCS		= pipex.c pipex_utils.c

OBJS		= $(SRCS:..c = o)

LIBFT_DIR	= ./libft

LIBFT_SRCS	= $(wildcard $LIBFT_DIR)/*.c

LIBFT_OBJS	= $(LIBFT_SRCS:.c=.o)

LIBFT		= $(LIBFT_DIR)/libft.a

CC 		= cc

FLAGS		= -Wall -Wextra -Werror

all: $(LIBFT) $(NAME)

$(LIBFT): $(LIBFT_OBJS)
	@echo  "\033[32mCreating libft library...\033[0m"
	ar rc $(LIBFT) $(LIBFT_OBJS)
	@ranlib $(LIBFT)

$(NAME): $(OBJS)
	@echo	"\033[34mCompiling...\033[0m"
	cc $(FLAGS) -c $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
$(LIBFT_OBJS): $(LIBFT_SRCS)
	cc $(FLAGS) -c $^

clean:
	@echo	"\033[33mCleaning library...\033[0m"
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)
	rm -f $(LIBFT_OBJS)

fclean: clean
	@echo	"\033[31mCleaning executable and library...\033[0m"
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
