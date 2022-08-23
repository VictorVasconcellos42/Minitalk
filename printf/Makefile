# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 04:36:32 by vde-vasc          #+#    #+#              #
#    Updated: 2022/07/19 09:54:08 by vde-vasc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

CFLAGS			= -Wall -Wextra -Werror 
CC				= gcc
LIBFLAGS		= -rcs
RM				= rm -f

D_LIBFT			= ./libft
LIBFT			= ./libft/libft.a

FT_PRINTF		= printf_utils.c ft_puthexa.c ft_printf.c argument_case.c 
OBJECTS			= $(FT_PRINTF:.c=.o)

all:	$(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	cp $(LIBFT) $(NAME)
	ar $(LIBFLAGS) $(NAME) $(OBJECTS)

$(LIBFT): $(D_LIBFT)
	$(MAKE) -C $(D_LIBFT)

clean:
	$(MAKE) clean -C $(D_LIBFT)
	$(RM) $(OBJECTS)

fclean:	clean
	$(MAKE) fclean -C $(D_LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
