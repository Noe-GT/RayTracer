##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

include ../../../Messages.mk

ROOT	=	../../..

SRCS_DIR	=	../..

CXX	=	g++
CXXFLAGS	=	-std=c++20 -Wall -Wextra -Werror -g3	\
				-I. -I$(SRCS_DIR)/shared -I$(SRCS_DIR)/lib/math
ifneq ($(shell uname -s), Darwin)
	CXXFLAGS	+=	-fno-gnu-unique
endif
LDFLAGS	=	-L$(SRCS_DIR)/lib/math/ -lmath -lconfig++
CPPFLAGS	=	\

BIN_DIR	=	bin
PLUGINS_DIR	=	$(ROOT)/plugins

SRCS	=	Scaling.cpp	\

OBJS	=	$(SRCS:%.cpp=$(BIN_DIR)/%.o)

SHARED_OBJS	=	$(SRCS_DIR)/shared/bin/APrimitive.o	\
				$(SRCS_DIR)/shared/bin/Material.o	\
				$(SRCS_DIR)/shared/bin/Exceptions.o	\

PLUGIN_NAME	=	scaling.so

PLUGIN	=	$(PLUGINS_DIR)/$(PLUGIN_NAME)

all:	$(PLUGIN)

$(PLUGIN):	$(OBJS) $(SHARED_OBJS)
	@mkdir -p $(PLUGINS_DIR)
	$(CXX) -shared -o $(PLUGIN) $(OBJS) $(SHARED_OBJS) $(LDFLAGS)
	@echo "  $(PLUGIN_MSG) $(PLUGIN_NAME) built"

$(BIN_DIR)/%.o:	%.cpp
	@mkdir -p $(BIN_DIR)
	@echo "    $(FILE_BUILD_MSG) Building $<"
	$(CXX) -fPIC -c $< -o $@ $(CXXFLAGS) $(CPPFLAGS)

clean:
	rm -rf $(BIN_DIR)

fclean:	clean

re:	fclean all

.PHONY:	all clean fclean re
