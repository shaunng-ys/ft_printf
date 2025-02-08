# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shaun <sng@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/26 21:56:20 by shaun             #+#    #+#              #
#    Updated: 2025/01/26 21:56:22 by shaun             ###   ########kl        #
#                                                                              #
# **************************************************************************** #

# Let me explain the difference between these Makefile rules:

# `fclean` (full clean):
# - Depends on the `clean` rule (will execute `clean` first)
# - Then removes the final program/library file ($(NAME))
# - Used when you want to remove all generated files, including the final executable

# `re` (rebuild):
# - Depends on `fclean` and `all` in that order
# - First does a full clean by running `fclean`
# - Then rebuilds everything from scratch by running `all`
# - Useful when you want to ensure a completely fresh build

# Example workflow:
# ```bash
# make clean   # Removes object files
# make fclean  # Removes object files AND final program
# make re      # Complete rebuild: clean everything and recompile
# ```

# Think of it as:
# - `clean`: Partial cleanup
# - `fclean`: Complete cleanup
# - `re`: Complete cleanup + rebuild

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

NAME = libftprintf.a

SRC = ft_strlen.c ft_putchar_fd.c ft_printf.c ft_putnbr_base.c ft_printf_util1.c ft_printf_util2.c

OBJS = ft_strlen.o ft_putchar_fd.o ft_printf.o ft_putnbr_base.o ft_printf_util1.o ft_printf_util2.o


all: $(NAME)

$(NAME): $(SRC)
		$(CC) $(CFLAGS) -c $(SRC)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re bonus
