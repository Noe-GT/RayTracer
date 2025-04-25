##
## EPITECH PROJECT, 2025
## Arcade
## File description:
## Makefile
##
DELETE_MSG   	= 		\033[1;31m[DELETE]:\033[0m
RESET	   		=		\033[0m
##################################################################

ROOT			=		../../

SRCS			=		ALight.cpp								\

NAME			=		directional

BIN_DIR			=		bin
OBJS			=		$(SRCS:%.cpp=$(BIN_DIR)/%.o)

CXX				=		g++

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	CXXFLAGS	=		-std=c++20 -Wall -Wextra -Werror -g3
else
	CXXFLAGS	=		-std=c++20 -Wall -Wextra -Werror -fno-gnu-unique -g3
endif
##################################################################

all:	$(OBJS) plugins

plugins:
	@$(foreach file, $(NAME), make -C $(file);)

$(BIN_DIR)/%.o:	%.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) -fPIC -c $< -o $@ $(CXXFLAGS)
##################################################################

clean:
	@rm -rf $(BIN_DIR)
	@echo "$(DELETE_MSG) light/bin"
	$(foreach file, $(NAME), make clean -C $(file);)

fclean:	clean
##################################################################

re:	fclean all

.PHONY:	all clean fclean re
