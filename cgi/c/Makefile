
NAME = script

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
RM = rm -rf

D_OBJ = obj/
OBJS = $(patsubst %.c,$(D_OBJ)%.o,$(SRCS))
SRCS =	main.c


#------------------------------------------------------------------------------#
#									 RULES									   #
#------------------------------------------------------------------------------#

all:	 $(NAME)

$(NAME):	$(D_OBJ) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "$(OK_COLOR)BOOM 💥💥💥💥💥 $(NAME) Compiled! 💯 $(DEFAULT)"

$(D_OBJ):
	@mkdir -p $(D_OBJ)

$(OBJS): $(D_OBJ)%.o : %.c
		@$(CC) $(CFLAGS) -c $< -o $@

run: re
	@clear
	@./$(NAME)

clean:
	@$(RM) $(D_OBJ)
	@echo "$(OK_COLOR)$(NAME) Cleaned 💯 $(DEFAULT)"

fclean:	clean
	@$(RM) $(NAME) $(NAME_BONUS)

re:	fclean all

.PHONY: all clean fclean re


#------------------------------------------------------------------------------#
#									 COLORS									   #
#------------------------------------------------------------------------------#

RED = \033[1;31m
YELLOW = \033[1;33m
DEFAULT = \033[0m
COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

summary:
	valgrind --leak-check=summary --trace-children=yes --track-fds=yes ./$(NAME)

valgrind:
	valgrind --leak-check=full  --show-leak-kinds=all --trace-children=yes --track-fds=yes ./$(NAME)