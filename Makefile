# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 09:31:21 by abouhlel          #+#    #+#              #
#    Updated: 2021/10/14 11:28:36 by abouhlel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= push_swap

#	FILES			############################################################
FOLDER_HEADER		= header/
FOLDER				= src/

HEADER_FILE 		= push_swap.h

SRCS				= 	ft_algo_2.c \
						ft_algo_3.c \
						ft_all_sorted.c \
						ft_big_algo.c \
						ft_errors.c \
						ft_move.c \
						ft_parsing.c \
						ft_reverse_rotate.c \
						ft_rotate.c \
						ft_search.c \
						ft_solve.c \
						ft_valid_arg.c \
						main.c \
						
SRC					= $(addprefix ${FOLDER},${SRCS})
HEADERS				= $(addprefix ${FOLDER_HEADER},${HEADER_FILE})

OBJS				= ${SRC:.c=.o}
####################################################################################

#	COMPILATION		################################################################
CC					= gcc
CFLAGS  			= -Wall -Wextra -Werror
RM					= rm -rf
MAKE_EXT			= @make -s --no-print-directory -C

OBJ					= ${OBJS}

UNAME_S				= $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	LIBS 			= -L ./libft -lft -lXext -lX11
endif
ifeq ($(UNAME_S),Darwin)
	LIBS 			= -L ./libft -lft -framework OpenGL -framework AppKit -lz
endif

COMPIL	= $(CC) $(CFLAGS) ${OBJ} $(LIBS) -o $(NAME)
#####################################################################################

#	RULES	#########################################################################
$(NAME):	${OBJ}
			@printf $(blue)
			@printf "\n"
			@printf $(magenta)
			$(MAKE_EXT) ./libft
			@$(COMPIL)
			@printf $(reset)

all:		${NAME}

%.o: %.c	$(HEADERS)
			@printf $(yellow)
			@printf "Generating push_swap objects... %-33.33s\r" $@
			@$(CC) -c $(CFLAGS) -o $@ $<
			@printf $(reset)

re: 		fclean all

clean:
			$(MAKE_EXT) ./libft clean
			@${RM} ${OBJ}
			@printf $(magenta)
			@printf "Object files have been deleted 🚮\n"
			@printf $(reset)

fclean:		clean
			$(MAKE_EXT) ./libft fclean
			@${RM} $(NAME)
			@printf $(magenta)
			@printf "Your folder is now clean 🧹\n"
			@printf $(reset)

.PHONY: 	all clean fclean re
#################################################################################

#	COLOR SETTING	#############################################################
black 				=	""
red 				=	""
green 				=	""
yellow 				=	""
blue 				=	""
magenta 			=	""
cyan 				=	""
white 				=	""

bg_black 			=	""
bg_red 				=	""
bg_green 			=	""
bg_yellow 			=	""
bg_blue 			=	""
bg_magenta 			=	""
bg_cyan 			=	""
bg_white 			=	""

reset 				=	""
#################################################################################
#                                                                               #
#                   ##                                             #####        #
#                   ##                                             #            #
#                   ##                                           #######        #
#                   ##                                              ##          #
#       #####       ##          ####           #    #    #          ##          #
#       #           ##         #    #          #    #    #          ##          #
#     ########      ########################### #### ####           ##          #
#                                                                               #
#################################################################################