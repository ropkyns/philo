# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 12:31:15 by paulmart          #+#    #+#              #
#    Updated: 2024/12/16 12:10:07 by paulmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	main.c chrono.c data_init.c dinner.c monitor.c \
					mutex_threads.c set.c utils.c utils_sync.c \
					write.c

OBJS			= $(SRCS:.c=.o)

HEADER			= philo.h
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

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