##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

RESET	   	=	\033[0m
MAGENTA	=	\033[0;35m

PLUGINS_DIR	=	../plugins/

PLUGINS	=	solid	\
			light	\

all:	print build

print:
	@echo -e "$(MAGENTA)[PLUGINS]$(RESET)"

build:
	@$(foreach file, $(PLUGINS), make -C $(file);)

clean:
	$(foreach file, $(PLUGINS), make clean -C $(file);)
	rm -f $(PLUGINS_DIR)*

fclean:	clean

re:	fclean all

.PHONY:	all print build clean fclean re
