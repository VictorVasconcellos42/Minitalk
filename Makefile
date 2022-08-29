# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 21:45:07 by vde-vasc          #+#    #+#              #
#    Updated: 2022/08/29 20:59:00 by vde-vasc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minitalk

B_SERVER	= server_bonus.c

B_CLIENT	= client_bonus.c

NAMELIB	=	libft.a

CLIENT	=	client

SERVER	= 	server

LIBFT	=	libft/libft.a

all: $(CLIENT) $(SERVER) $(NAMELIB)

$(NAMELIB):
	$(MAKE) -C libft/.
	cp $(LIBFT) ./ 

$(CLIENT): $(NAMELIB)
	gcc -Wall -Wextra -Werror client.c $(NAMELIB) -o $(CLIENT)

$(SERVER): $(NAMELIB)
	gcc -Wall -Wextra -Werror server.c $(NAMELIB) -o $(SERVER)

$(B_CLIENT): $(NAMELIB)
	gcc -Wall -Wextra -Werror $(B_CLIENT) $(NAMELIB) -o $(CLIENT)

$(B_SERVER): $(NAMELIB)
	gcc -Wall -Wextra -Werror $(B_SERVER) $(NAMELIB) -o $(SERVER)

bonus: $(B_SERVER) $(B_CLIENT) $(NAMELIB)

clean:
	@$(MAKE) fclean -C ./libft

fclean: clean
	@rm -rf $(SERVER)
	@rm -rf $(CLIENT)
	@rm -rf $(NAMELIB)

re: fclean all
