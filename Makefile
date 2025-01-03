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

BNS_SRCS 	= pipex_bonus.c pipex_utils_bonus.c

OBJS		= $(SRCS:..c = o)

LIBFT_DIR	= ./libft

LIBFT_SRCS	= $(LIBFT_DIR)/ft_*.c

LIBFT_OBJS	= $(LIBFT_SRCS:.c=.o)

LIBFT		= $(LIBFT_DIR)/libft.a

BNS_OBJS	= $(BNS_SRCS:.c=.o)

CC 		= cc

FLAGS		= -Wall -Wextra -Werror

all: $(LIBFT) $(NAME)

$(LIBFT): $(LIBFT_OBJS)
	@echo  "Library created"
	ar rc $(LIBFT) $(LIBFT_OBJS)
	@ranlib $(LIBFT)

$(NAME): $(OBJS)
	cc $(FLAGS) -c $(NAME) $(OBJS) $(LIBFT)

$(LIBFT_OBJS): $(LIBFT_SRCS)
	cc $(FLAGS) -c $^ -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)
	rm -f $(LIBFT_OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

bonus:
	$(MAKE) -C $(LIBFT_DIR) bonus

.PHONY: all clean fclean re
