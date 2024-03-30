# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 03:33:36 by ryoshio-          #+#    #+#              #
#    Updated: 2024/02/29 03:51:15 by ryoshio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = webserv

CC = c++
RM = rm -rf
CFLAGS = -g -Wall -Wextra -Werror -std=c++98

INCLUDES = -I includes
DIR_SOURCES = src
DIR_OBJS = build


SOURCES := $(wildcard $(DIR_SOURCES)/*.cpp)

OBJS :=  $(subst $(DIR_SOURCES),$(DIR_OBJS),$(SOURCES:.cpp=.o))

all: $(NAME)

$(DIR_OBJS)/%.o: $(DIR_SOURCES)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(DIR_OBJS):
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)


clean:
	$(RM) $(DIR_OBJS)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

val: all
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --log-file="web_leaks.txt" ./$(NAME)

.PHONY: all clean fclean re val 
