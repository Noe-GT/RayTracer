##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

ROOT	=	../..

CXX	=	g++
CXXFLAGS	=	-std=c++20 -Wall -Wextra -Werror -g3	\
				-L$(ROOT)/lib/math/ -lmath -I. -I../../shared -I../../lib/math
ifneq ($(shell uname -s), Darwin)
	CXXFLAGS	+=	-fno-gnu-unique
endif
CPPFLAGS	=	\

BIN_DIR	=	bin
PLUGINS_DIR	=	../../../plugins

SRCS	=	Scaling.cpp	\

OBJS	=	$(SRCS:%.cpp=$(BIN_DIR)/%.o)

SHARED_OBJS	=	$(ROOT)/shared/bin/*.o

PLUGIN	=	$(PLUGINS_DIR)/scaling.so

all:	$(PLUGIN)

$(PLUGIN):	$(OBJS)
	@mkdir -p $(PLUGINS_DIR)
	$(CXX) -shared -o $(PLUGIN) $(OBJS) $(SHARED_OBJS)

$(BIN_DIR)/%.o:	%.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) -fPIC -c $< -o $@ $(CXXFLAGS) $(CPPFLAGS)

clean:
	rm -rf $(BIN_DIR)

fclean:	clean

re:	fclean all

.PHONY:	all clean fclean re
