##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

CXX	=	g++
CXXFLAGS	=	-std=c++20 -Wall -Wextra -Werror -g3	\
				-I. -I../../shared
CPPFLAGS	=	\

BIN_DIR	=	bin

SRCS	=	CollisionUtils.cpp	\
			Color.cpp	\
			Noise.cpp	\
			Point.cpp	\
			Ray.cpp	\
			Vector.cpp	\

OBJS	=	$(SRCS:%.cpp=$(BIN_DIR)/%.o)

LIB	=	libmath.a

all:	$(LIB)

$(LIB):	$(OBJS)
	ar rc -o $(LIB) $(OBJS)

$(BIN_DIR)/%.o:	%.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) -fPIC -c $< -o $@ $(CXXFLAGS) $(CPPFLAGS)

clean:
	rm -rf $(BIN_DIR)

fclean:	clean
	rm -rf $(LIB)

re:	fclean all

.PHONY:	all clean fclean re
