##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

include Messages.mk

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
	$(MAKE) libs shared plugins core
	@echo "$(BUILD_MSG) Raytracer built"

libs:
	make -C $(LIBS_DIR)

shared:
	make -C $(SHARED_DIR)

plugins:
	make -C $(PLUGINS_DIR)

core:
	make -C $(CORE_DIR)

clean:
	$(foreach file, $(ALL_DIRS), make clean -C $(file);)
	@echo "$(DELETE_MSG) Cleaning all object files"

fclean:	clean
	$(foreach file, $(ALL_DIRS), make fclean -C $(file);)
	@echo "$(DELETE_MSG) Cleaning all shared libraries, static libraries and \
	project binaries"

re:	fclean all

.PHONY:	all clean fclean re
