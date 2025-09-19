NAME			= Philosopher

#		Couleurs		#

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m
TEAL			= \033[0;36m
PURPLE			= \033[0;35m
CYAN            = \033[0;36m
MAGENTA         = \033[0;35m


#		FLags & Commandes CLI		#

CC 				= cc
REMOVE 			= rm -f
STANDARD_FLAGS 	= -g -Wall -Wextra -Werror
GDB_FLAGS		= -g3
VALGRIND		= valgrind --tool=helgrind

#		Directories			#

SRCS_DIR		= ./SRC/
UTILS_DIR		= ./Utils/

SRCS 			= $(addprefix $(SRCS_DIR),\
                Philo.c main.c)
UTILS			= $(addprefix $(UTILS_DIR), \
                utils_philo.c utils_print.c utils_set.c \
				utils_sleep.c utils_time.c utils_parsing.c)

#		Fonction		#	

all: 		${NAME}

${NAME}:        
				${CC} ${SRCS} ${UTILS} ${STANDARD_FLAGS} -o ${NAME}
clean:
				${REMOVE} ${NAME} Test
				@echo "$(TEAL)Cleaning object files and temporary files...$(RESET)"

fclean:
				${REMOVE} ${NAME} Test

gdb:
				cc ${STANDARD_FLAGS} -g3 ${SRCS} ${UTILS} -o debug

re:				fclean all

.PHONY:			all clean fclean re valgrind run