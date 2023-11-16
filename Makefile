# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adenord <alexandre.denord@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 07:47:37 by adenord           #+#    #+#              #
#    Updated: 2023/11/16 18:26:39 by adenord          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


MAKEFLAGS += --silent

SRCS_SRV := srv/
SRCS_CLI := cli/
CC := gcc
CPPFLAGS := -I includes/ -I srcs/libft
CFLAGS := -Wall -Wextra -Werror

LIBFT := srcs/libft/libft.a
MAIN_SRV := srcs/srv/server.c
MAIN_CLI := srcs/cli/client.c
NAME_CLI := client
NAME_SRV := server
MAIN_SRV_B := srcs/srv/server_bonus.c
MAIN_CLI_B := srcs/cli/client_bonus.c
NAME_CLI_B := client_bonus
NAME_SRV_B := server_bonus

all : writing $(NAME_SRV) $(NAME_CLI)

re : fclean all 

bonus : writing_bonus $(NAME_SRV_B) $(NAME_CLI_B)

writing :
	echo "\033[32mCreating your binaries ...\033[0m"
		
writing_bonus :
	echo "\033[32mCreating your binaries (bonus) ...\033[0m"

libft :
	make -C srcs/libft/

$(NAME_SRV) : libft
	$(CC) $(CFLAGS) $(MAIN_SRV) $(LIBFT) -o $(NAME_SRV) $(CPPFLAGS)
	echo "\033[32mDone !\033[0m"

$(NAME_CLI) : libft
	$(CC) $(CFLAGS) $(MAIN_CLI) $(LIBFT) -o $(NAME_CLI) $(CPPFLAGS)

$(NAME_SRV_B) : libft
	$(CC) $(CFLAGS) $(MAIN_SRV_B) $(LIBFT) -o $(NAME_SRV_B) $(CPPFLAGS)

$(NAME_CLI_B) : libft
	$(CC) $(CFLAGS) $(MAIN_CLI_B) $(LIBFT) -o $(NAME_CLI_B) $(CPPFLAGS)
	echo "\033[32mDone !\033[0m"

clean :
	echo "\033[32mObjects files have been deleted.\033[0m"
	make clean -C srcs/libft

fclean : clean
	echo "\033[32mBinaries have been deleted.\033[0m"
	$(RM) $(LIBFT) $(NAME_CLI) $(NAME_SRV) $(NAME_CLI_B) $(NAME_SRV_B)

re : fclean all
