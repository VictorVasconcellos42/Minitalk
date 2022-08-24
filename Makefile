# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 21:45:07 by vde-vasc          #+#    #+#              #
#    Updated: 2022/08/24 14:16:51 by vde-vasc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT	=	client

SERVER	= 	server

NAME	=	libft.a

LIBFT	=	libft/libft.a

all: $(CLIENT) $(SERVER) $(NAME)

$(NAME):
	$(MAKE) -C libft/.
	cp $(LIBFT) ./ 

$(CLIENT): $(NAME)
	gcc -Wall -Wextra -Werror client.c $(NAME) -o $(CLIENT)

$(SERVER): $(NAME)
	gcc -Wall -Wextra -Werror server.c $(NAME) -o $(SERVER)

clean:
	@$(MAKE) fclean -C ./libft

fclean: clean
	rm -rf $(SERVER)
	rm -rf $(CLIENT)
	rm -rf $(NAME)

re: fclean all
