# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 09:31:21 by abouhlel          #+#    #+#              #
#    Updated: 2021/10/21 15:47:02 by abouhlel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= push_swap
NAME_CHK			= checker
############################ * F I L E S * #####################################
FOLDER_HEADER		= header/
FOLDER				= src/
CHK_FOLDER			= mychecker/

HEADER_FILE 		= push_swap.h

SRCS				= 	ft_valid_arg.c \
						ft_big_algo.c \
						ft_utils_a.c \
						ft_utils_b.c \
						ft_parsing.c \
						ft_search.c \
						ft_solve.c \
						ft_meet.c \
						
MAIN				=	ft_move.c \
						ft_move2.c \
						main.c \
						
BONUS				= 	Checker.c \
						ft_mv.c \
						ft_mv2.c \
						ft_utils.c \

HEADERS				= $(addprefix ${FOLDER_HEADER},${HEADER_FILE})												
SRC					= $(addprefix ${FOLDER},${SRCS})
MN					= $(addprefix ${FOLDER},${MAIN})
CHK					= $(addprefix ${CHK_FOLDER},${BONUS})

OBJS				= ${SRC:.c=.o}
OBJ_MN				= ${MN:.c=.o}
OBJ_CHK				= ${CHK:.c=.o}
####################################################################################

######################### * C O M P I L A T I O N * ##############################
CC					= gcc
CFLAGS  			= -Wall -Wextra -Werror -g 
RM					= rm -rf
MAKE_EXT			= @make -s --no-print-directory -C

OBJ					= ${OBJS} ${OBJ_MN}
OBJ_BONUS			= ${OBJS} ${OBJ_CHK}

UNAME_S				= $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	LIBS 			= -L ./libft -lft -lXext -lX11
endif
ifeq ($(UNAME_S),Darwin)
	LIBS 			= -L ./libft -lft -framework OpenGL -framework AppKit -lz
endif

COMPIL			= $(CC) $(CFLAGS) ${OBJ} $(LIBS) -o $(NAME)
COMPIL_BONUS	= $(CC) $(CFLAGS) ${OBJ_BONUS} $(LIBS) -o $(NAME_CHK)

#####################################################################################

################################# * R U L E S * #####################################
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

bonus:		${OBJ_BONUS}
			@printf $(blue)
			@printf "Generating checker objects... %-33.33s\r" $@
			@printf $(magenta)
			$(MAKE_EXT) ./libft
			@$(COMPIL_BONUS)
			@printf $(reset)
			
re: 		fclean all

clean:
			$(MAKE_EXT) ./libft clean
			@${RM} ${OBJ} ${OBJ_BONUS}
			@printf $(magenta)
			@printf "Object files have been deleted 🚮\n"
			@printf $(reset)

fclean:		clean
			$(MAKE_EXT) ./libft fclean
			@${RM} $(NAME) $(NAME_CHK)
			@printf $(magenta)
			@printf "Your folder is now clean 🧹\n"
			@printf $(reset)

.PHONY: 	all clean fclean re bonus
#################################################################################

############################### * C O L O R S * #################################
black 				=	"[1;30m"
red 				=	"[1;31m"
green 				=	"[1;32m"
yellow 				=	"[1;33m"
blue 				=	"[1;34m"
magenta 			=	"[1;35m"
cyan 				=	"[1;36m"
white 				=	"[1;37m"

bg_black 			=	"[40m"
bg_red 				=	"[41m"
bg_green 			=	"[42m"
bg_yellow 			=	"[43m"
bg_blue 			=	"[44m"
bg_magenta 			=	"[45m"
bg_cyan 			=	"[46m"
bg_white 			=	"[47m"

reset 				=	"[0m"

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
