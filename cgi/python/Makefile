
run:
	@python3 app.py

setup:	requirements.txt
	@pip install -r requirements.txt

fclean:
	@rm -rf __pycache__
	@echo "$(OK_COLOR)Cleaned 💯 $(DEFAULT)"

re:	fclean run

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
