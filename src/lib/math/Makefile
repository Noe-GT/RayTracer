##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

include ../../../Messages.mk

SRCS_DIR	=	../..

CXX	=	g++
CXXFLAGS	=	-std=c++20 -Wall -Wextra -Werror -g3	\
				-I. -I$(SRCS_DIR)/shared
CPPFLAGS	=	\

ifeq ($(shell uname), Darwin)
    AR = libtool
    AR_FLAGS = -static -o
else
	AR = ar
	AR_FLAGS = rc -o
endif

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
	$(AR) $(AR_FLAGS) $(LIB) $(OBJS)
	@echo "  $(LIB_MSG) $(LIB) built"

$(BIN_DIR)/%.o:	%.cpp
	@mkdir -p $(BIN_DIR)
	@echo "    $(FILE_BUILD_MSG) Building $<"
	$(CXX) -fPIC -c $< -o $@ $(CXXFLAGS) $(CPPFLAGS)

clean:
	rm -rf $(BIN_DIR)

fclean:	clean
	rm -rf $(LIB)

re:	fclean all

.PHONY:	all clean fclean re
