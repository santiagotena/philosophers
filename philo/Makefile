# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 23:26:30 by stena-he          #+#    #+#              #
#    Updated: 2023/01/10 22:10:44 by stena-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= a.out
CC		= gcc
CFLAGS	= -Werror -Wall -Wextra -pthread -g

SRC_PATH = src/
OBJ_PATH = obj/
INC_PATH = inc/

SRC		=	main.c \
			parse_args.c \
			sole_philo.c \
			philosophers.c \
			routines.c \
			actions.c \
			fork_actions.c \
			utils.c
			
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