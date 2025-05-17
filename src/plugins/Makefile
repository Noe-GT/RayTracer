##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

include ../../Messages.mk

PLUGINS	=	rotation	\
			scaling	\
			SFML	\
			sphere	\
			cone	\
			translation	\
			infinite_plan	\
			cylinder	\

PLUGINS_DIR	=	../../plugins

all:
	@mkdir -p $(PLUGINS_DIR)
	$(foreach file, $(PLUGINS), make -C $(file);)

clean:
	$(foreach file, $(PLUGINS), make clean -C $(file);)

fclean:	clean
	rm -rf $(PLUGINS_DIR)

re:	fclean all

.PHONY:	all clean fclean re
