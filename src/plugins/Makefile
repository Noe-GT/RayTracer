##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

PLUGINS	=	rotation	\
			scaling	\
			SFML	\
			sphere	\
			translation	\
			infinite_plan	\

PLUGINS_DIR	=	../../plugins

all:
	@mkdir -p $(PLUGINS_DIR)
	$(foreach file, $(PLUGINS), make -C $(file);)

clean:
	$(foreach file, $(PLUGINS), make clean -C $(file);)
	@rm -rf $(PLUGINS_DIR)

fclean:	clean

re:	fclean all

.PHONY:	all clean fclean re
