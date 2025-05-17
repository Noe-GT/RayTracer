##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

include ../Messages.mk

ROOT	=	..
SRCS_DIR	=	src
CORE_DIR	=	$(ROOT)/$(SRCS_DIR)/core
LIBS_DIR	=	$(ROOT)/$(SRCS_DIR)/lib
SHARED_DIR	=	$(ROOT)/$(SRCS_DIR)/shared

CXX	=	g++
CXXFLAGS	=	-std=c++20 -Wall -Wextra -Werror -g3	\
				-I. -I$(CORE_DIR) -I$(LIBS_DIR)/math -I$(SHARED_DIR)
LDFLAGS	=	-lcriterion -lconfig++ -L$(LIBS_DIR)/math -lmath
CPPFLAGS	=	\

BIN_DIR	=	bin

SRCS	=	tests_ray.cpp	\

OBJS	=	$(SRCS:%.cpp=$(BIN_DIR)/%.o)

EXEC	=	$(ROOT)/unit_tests

all:	$(EXEC)

$(EXEC):	$(OBJS)
	$(CXX) -o $(EXEC) $(OBJS) $(LDFLAGS)
	@echo "$(BUILD_MSG) Unit tests built"

$(BIN_DIR)/%.o:	%.cpp
	@mkdir -p $(BIN_DIR)
	@echo "  $(FILE_BUILD_MSG) Building $<"
	$(CXX) -c $< -o $@ $(CXXFLAGS) $(CPPFLAGS)

clean:
	rm -rf $(BIN_DIR)

fclean:	clean
	rm -rf $(EXEC)

re:	fclean all

.PHONY:	all clean fclean re
