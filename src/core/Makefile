##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

include ../../Messages.mk

ROOT	=	../..

SRCS_DIR	=	..

CXX	=	g++
CXXFLAGS	=	-std=c++20 -Wall -Wextra -Werror -g3	\
				-I. -I$(SRCS_DIR)/shared -I$(SRCS_DIR)/threading -I$(SRCS_DIR)/lib/math
LDFLAGS	=	-lconfig++ -L$(SRCS_DIR)/lib/math -lmath
CPPFLAGS	=	\

BIN_DIR	=	bin

SRCS	=	Main.cpp	\
			Camera.cpp	\
			LibLister.cpp	\
			Parser.cpp	\
			Pixel.cpp	\
			PluginHandler.cpp	\
			RayTracer.cpp	\
			Scene.cpp	\
			RenderPool.cpp	\

OBJS	=	$(SRCS:%.cpp=$(BIN_DIR)/%.o)

SHARED_OBJS	=	$(SRCS_DIR)/shared/bin/Exceptions.o	\
				$(SRCS_DIR)/shared/bin/Material.o	\

EXEC	=	$(ROOT)/raytracer

all:	$(EXEC)

$(EXEC):	$(OBJS) $(SHARED_OBJS)
	$(CXX) -o $(EXEC) $(OBJS) $(SHARED_OBJS) $(LDFLAGS)
	@echo "  $(BUILD_MSG) Core files built"

$(BIN_DIR)/%.o:	%.cpp
	@mkdir -p $(BIN_DIR)
	@echo "    $(FILE_BUILD_MSG) Building $<"
	$(CXX) -fPIC -c $< -o $@ $(CXXFLAGS) $(CPPFLAGS)

clean:
	rm -rf $(BIN_DIR)

fclean:	clean
	rm -rf $(EXEC)

re:	fclean all

.PHONY:	all clean fclean re
