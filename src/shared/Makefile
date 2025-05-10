##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

CXX	=	g++
CXXFLAGS	=	-std=c++20 -Wall -Wextra -Werror -g3	\
				-I. -I../lib/math
LDFLAGS	=	-lconfig++
CPPFLAGS	=	\

BIN_DIR	=	bin

SRCS	=	APrimitive.cpp	\
			Exceptions.cpp	\
			Material.cpp	\

OBJS	=	$(SRCS:%.cpp=$(BIN_DIR)/%.o)

all:	$(OBJS)

$(BIN_DIR)/%.o:	%.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) -fPIC -c $< -o $@ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS)

clean:
	rm -rf $(BIN_DIR)

fclean:	clean

re:	fclean all

.PHONY:	all clean fclean re
