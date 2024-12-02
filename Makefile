# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: palu <palu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 12:31:15 by paulmart          #+#    #+#              #
#    Updated: 2024/11/25 20:52:36 by palu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	src/main.c src/chrono.c src/data_init.c src/dinner.c src/monitor.c \
					src/mutex_threads.c src/set.c src/utils.c src/utils_sync.c \
					src/write.c

OBJS			= $(SRCS:.c=.o)

HEADER			= philo.h
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -std=gnu99

NAME			= philo


all:			$(NAME)	

$(NAME):		$(OBJS)
				$(CC) -o $(NAME) $(OBJS) -lpthread

clean:
				$(RM) $(OBJS)
				$(RM) *~

fclean:			clean
				$(RM) $(NAME)

re:				fclean
	$(MAKE) $(NAME)

.PHONY: all clean fclean re