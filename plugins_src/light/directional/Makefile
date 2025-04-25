##
## EPITECH PROJECT, 2025
## Arcade
## File description:
## Makefile
##

PLUGIN_MSG   	=	 	\033[1m\033[1;36m[PLUGIN]:\033[0m
BUILD_MSG    	=	 	\033[1m\033[1;32m[BUILD]:\033[0m
DELETE_MSG   	=	 	\033[1m\033[1;31m[DELETE]:\033[0m
##################################################################

ROOT			=		../../../
PLUGIN_DIR		=		$(ROOT)plugins/

PLUGIN_SRC_DIR	=		$(ROOT)plugins_src/
SRCS			=		DirectionalLight.cpp \

BIN_DIR			=		bin
OBJS			=		$(SRCS:%.cpp=$(BIN_DIR)/%.o)
SUPER_OBJS		=		../bin/*.o

LIB				=		$(PLUGIN_DIR)DirectionalLight.so

CXX				=		g++

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	CXXFLAGS	=		-std=c++20 -Wall -Wextra -Werror -g3
else
	CXXFLAGS	=		-std=c++20 -Wall -Wextra -Werror -fno-gnu-unique -g3
endif
##################################################################

all:	print $(LIB)

print:
	@echo "  │   ├─$(PLUGIN_MSG) building DirectionalLight.so ...";

$(LIB):	$(OBJS)
	@mkdir -p $(PLUGIN_DIR)
	$(CXX) -shared -o $(LIB) $(SUPER_OBJS) $(OBJS)

$(BIN_DIR)/%.o:	%.cpp
	@mkdir -p $(BIN_DIR)
	@if [ "$(lastword $(SRCS))" = "$<" ]; then 					\
		echo "  │   │   └── $(BUILD_MSG) $<"; 					\
	else 														\
		echo "  │   │   ├── $(BUILD_MSG) $<"; 					\
	fi
	$(CXX) -fPIC -c $< -o $@ $(CXXFLAGS) -I$(PLUGIN_SRC_DIR)light
##################################################################

clean:
	@echo "$(DELETE_MSG) directional light/bin"
	@rm -rf $(BIN_DIR)

fclean:	clean
##################################################################

re:	fclean all

.PHONY:	all clean fclean re
