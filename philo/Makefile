# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 23:26:30 by stena-he          #+#    #+#              #
#    Updated: 2023/01/15 04:50:08 by stena-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
CC		= gcc
CFLAGS	= -Werror -Wall -Wextra -pthread -g
# CFLAGS	= -Werror -Wall -Wextra -pthread -g -fsanitize=thread

SRC_PATH = src/
OBJ_PATH = obj/
INC_PATH = inc/

SRC		=	main.c \
			parse_args.c \
			sole_philo.c \
			philosophers.c \
			philosophers_cont.c \
			routines.c \
			actions.c \
			fork_actions.c \
			conditionals.c \
			sleep.c \
			get_time.c
			
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INC		= -I $(INC_PATH)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean