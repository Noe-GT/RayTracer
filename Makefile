##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

PLUGINS_SRC_DIR	=	plugins_src/

SRC_DIR	=	src/
SRC	=	$(SRC_DIR)main.cpp \
		$(SRC_DIR)RayTracer.cpp	\
		$(SRC_DIR)Exceptions.cpp	\
		$(SRC_DIR)pluginHandling/LibLister.cpp	\

LIB_DIR	=	libs/
LIBS_SRC	=	$(LIB_DIR)math	\

EXEC	=	raytracer

CXX	=	g++

CXXFLAGS	=	-std=c++20 -Wall -Wextra -Werror -g3

SFML_FLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system

OBJS_DIR	=	bin/

LIBS	=	-L libs/math -lmath

OBJS	=	$(SRC:cpp/%cpp=OBJS_DIR/%o)

all: libs plugins $(EXEC)

plugins:
	make -C $(PLUGINS_SRC_DIR)

libs:
	$(foreach file, $(LIBS_SRC), make -C $(file);)

$(EXEC):	$(OBJS)
	mkdir -p $(SRC_DIR)$(OBJS_DIR)
	$(CXX) -o $(EXEC) $(OBJS) $(LIBS) -I$(LIB_DIR) -I$(SRC_DIR) -I$(PLUGINS_SRC_DIR)

clean:
	rm -rf $(SRC_DIR)$(OBJS_DIR)
	make clean -C $(PLUGINS_SRC_DIR)
	$(foreach file, $(LIBS_SRC), make clean -C $(file);)

fclean:	clean
	rm -f $(EXEC)
	$(foreach file, $(LIBS_SRC), make fclean -C $(file);)

re:	fclean all

.PHONY:	all libs plugins source clean fclean re
