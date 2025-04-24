##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

PLUGINS_DIR	=	../plugins/

PLUGINS	=	solid	\

all: build

build:
	$(foreach file, $(PLUGINS), make -C $(file);)

clean:
	$(foreach file, $(PLUGINS), make clean -C $(file);)
	rm -f $(PLUGINS_DIR)*

fclean:	clean

re:	fclean all

.PHONY:	all build clean fclean re
