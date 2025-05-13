##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

SRCS_DIR	=	src

LIBS_DIR	=	$(SRCS_DIR)/lib
SHARED_DIR	=	$(SRCS_DIR)/shared
PLUGINS_DIR	=	$(SRCS_DIR)/plugins
CORE_DIR	=	$(SRCS_DIR)/core

ALL_DIRS	=	$(LIBS_DIR)	\
				$(SHARED_DIR)	\
				$(PLUGINS_DIR)	\
				$(CORE_DIR)	\

all:
	$(foreach file, $(ALL_DIRS), make -C $(file);)

clean:
	$(foreach file, $(ALL_DIRS), make clean -C $(file);)

fclean:	clean
	$(foreach file, $(ALL_DIRS), make fclean -C $(file);)

re:	fclean all

.PHONY:	all clean fclean re
