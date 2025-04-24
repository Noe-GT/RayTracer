##
## EPITECH PROJECT, 2025
## Arcade
## File description:
## Makefile
##

RESET	   	=	\033[0m
CYAN	=	\033[0;36m

ROOT	=	../../

SRCS	=	ALight.cpp	\

PLUGINS	=	directional	\

CXX	=	g++

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
CXXFLAGS	=	-std=c++20 -Wall -Wextra -Werror -g3
else
CXXFLAGS	=	-std=c++20 -Wall -Wextra -Werror -fno-gnu-unique -g3
endif

BIN_DIR	=	bin

OBJS	=	$(SRCS:%.cpp=$(BIN_DIR)/%.o)

all:	$(OBJS) plugins

plugins:
	@$(foreach file, $(PLUGINS), echo -e "$(CYAN)plugin: $(file)$(RESET)" ; make -C $(file);)

$(BIN_DIR)/%.o:	%.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) -fPIC -c $< -o $@ $(CXXFLAGS)

clean:
	rm -rf $(BIN_DIR)
	$(foreach file, $(PLUGINS), make clean -C $(file);)

fclean:	clean

re:	fclean all

.PHONY:	all clean fclean re
