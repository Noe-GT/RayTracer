##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

PLUGIN_DIR	=	plugins/
PLUGINS	=	$(PLUGIN_DIR)solid	\

SRC_DIR	=	src/
SRC	=	$(SRC_DIR)Main.cpp \

EXEC	=	raytracer

CXX	=	g++

CXXFLAGS	=	-std=c++20 -Wall -Wextra -Werror -g3

SFML_FLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system

OBJS_DIR	=	bin/

OBJS	=	$(SRC:cpp/%cpp=OBJS_DIR/%o)

all: $(EXEC) plugins

plugins:
	$(foreach file, $(PLUGINS), make -C $(file);)

$(EXEC):	$(OBJS)
	mkdir -p $(SRC_DIR)$(OBJS_DIR)
	$(CXX) -o $(EXEC) $(OBJS) -I $(SRC_DIR)

clean:
	rm -rf $(SRC_DIR)$(OBJS_DIR)
	$(foreach file, $(PLUGINS), make clean -C $(file);)

fclean:	clean
	rm -f $(EXEC)

re:	fclean all

.PHONY:	all plugins source clean fclean re
