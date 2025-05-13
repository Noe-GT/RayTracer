##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

include ../../Messages.mk

SRCS_DIR	=	..

CXX	=	g++
CXXFLAGS	=	-std=c++20 -Wall -Wextra -Werror -g3	\
				-I. -I$(SRCS_DIR)/lib/math
CPPFLAGS	=	\

BIN_DIR	=	bin

SRCS	=	APrimitive.cpp	\
			Exceptions.cpp	\
			Material.cpp	\

OBJS	=	$(SRCS:%.cpp=$(BIN_DIR)/%.o)

all:	$(OBJS)

$(BIN_DIR)/%.o:	%.cpp
	@mkdir -p $(BIN_DIR)
	@echo "  $(FILE_BUILD_MSG) Building $<"
	$(CXX) -fPIC -c $< -o $@ $(CXXFLAGS) $(CPPFLAGS)

clean:
	rm -rf $(BIN_DIR)

fclean:	clean

re:	fclean all

.PHONY:	all clean fclean re
