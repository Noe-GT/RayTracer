##
## EPITECH PROJECT, 2025
## Arcade
## File description:
## Makefile
##

DELETE_MSG		=		\033[1m\033[1;31m[DELETE]:\033[0m
##################################################################

ROOT			=		../../
PLUGIN_DIR		=		$(ROOT)../dynamic_libs_bin/

SRCS			=		Sphere.cpp 								\

OBJS_DIR		=		../sphere_bin
SUPER_OBJS		=		../../solid_bin/*.o
OBJS			=		$(SRCS:%.cpp=$(OBJS_DIR)/%.o)

CXX				=		g++

NAME			=		$(PLUGIN_DIR)Sphere.so

UNAME_S 		= 		$(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	CXXFLAGS	=		-std=c++20 -Wall -Wextra -Werror -g3
else
	CXXFLAGS	=		-std=c++20 -Wall -Wextra -Werror -fno-gnu-unique -g3
endif
##################################################################

all:	$(NAME)

$(NAME):	$(OBJS)
	@mkdir -p $(PLUGIN_DIR)
	$(CXX) -shared -o $(NAME) $(SUPER_OBJS) $(OBJS)

$(OBJS_DIR)/%.o:	%.cpp
	@mkdir -p $(OBJS_DIR)
	$(CXX) -fPIC -c $< -o $@ $(CXXFLAGS) -I$(ROOT)solid
##################################################################

clean:
	@echo "$(DELETE_MSG) sphere/bin"
	rm -rf $(OBJS_DIR)

fclean:	clean
##################################################################

re:	fclean all

.PHONY:	all clean fclean re
