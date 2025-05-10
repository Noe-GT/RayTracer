##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

ROOT	=	../..

CXX	=	g++
CXXFLAGS	=	-std=c++20 -Wall -Wextra -Werror -g3	\
				-I. -I../shared -I../lib/math
LDFLAGS	=	-lconfig++ -L../lib/math -lmath
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

OBJS	=	$(SRCS:%.cpp=$(BIN_DIR)/%.o)

SHARED_OBJS	=	../shared/bin/*.o

EXEC	=	$(ROOT)/raytracer

all:	$(EXEC)

$(EXEC):	$(OBJS)
	$(CXX) -o $(EXEC) $(OBJS) $(SHARED_OBJS) $(LDFLAGS)

$(BIN_DIR)/%.o:	%.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) -fPIC -c $< -o $@ $(CXXFLAGS) $(CPPFLAGS)

clean:
	rm -rf $(BIN_DIR)

fclean:	clean
	rm -rf $(EXEC)

re:	fclean all

.PHONY:	all clean fclean re
