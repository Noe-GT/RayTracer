##
## EPITECH PROJECT, 2025
## Arcade
## File description:
## Makefile
##

PLUGIN_DIR	=	../../../plugins/

PLUGIN_SRC_DIR	=	../../

CXX	=	g++

CXXFLAGS	=	-std=c++20 -Wall -Wextra -Werror -fno-gnu-unique -g3

CPPFLAGS	=	-I$(PLUGIN_SRC_DIR)solid

BIN_DIR	=	bin

SRCS	=	Sphere.cpp \

OBJS	=	$(SRCS:%.cpp=$(BIN_DIR)/%.o)

SUPER_OBJS	=	../bin/*.o

LIB	=	$(PLUGIN_DIR)sphere.so

all:	$(LIB)

$(LIB):	$(OBJS)
	@mkdir -p $(PLUGIN_SRC_DIR)
	$(CXX) -shared -o $(LIB) $(SUPER_OBJS) $(OBJS)

$(BIN_DIR)/%.o:	%.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) -fPIC -c $< -o $@ $(CXXFLAGS) $(CPPFLAGS)

clean:
	rm -rf $(BIN_DIR)

fclean:	clean

re:	fclean all

.PHONY:	all clean fclean re
