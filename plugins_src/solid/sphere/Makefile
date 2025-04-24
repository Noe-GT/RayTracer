##
## EPITECH PROJECT, 2025
## Arcade
## File description:
## Makefile
##

ROOT	=	../../../

PLUGIN_DIR	=	$(ROOT)plugins/

PLUGIN_SRC_DIR	=	$(ROOT)plugins_src/

CXX	=	g++

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
CXXFLAGS	=	-std=c++20 -Wall -Wextra -Werror -g3
else
CXXFLAGS	=	-std=c++20 -Wall -Wextra -Werror -fno-gnu-unique -g3
endif

BIN_DIR	=	bin

SRCS	=	Sphere.cpp \

OBJS	=	$(SRCS:%.cpp=$(BIN_DIR)/%.o)

SUPER_OBJS	=	../bin/*.o

LIB	=	$(PLUGIN_DIR)sphere.so

all:	$(LIB)

$(LIB):	$(OBJS)
	@mkdir -p $(PLUGIN_DIR)
	$(CXX) -shared -o $(LIB) $(SUPER_OBJS) $(OBJS)

$(BIN_DIR)/%.o:	%.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) -fPIC -c $< -o $@ $(CXXFLAGS) -I$(PLUGIN_SRC_DIR)solid

clean:
	rm -rf $(BIN_DIR)
	rm -f $(LIB)

fclean:	clean

re:	fclean all

.PHONY:	all clean fclean re
