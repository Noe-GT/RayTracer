##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

LIBS	=	math	\

all:
	$(foreach file, $(LIBS), make -C $(file);)

clean:
	$(foreach file, $(LIBS), make clean -C $(file);)

fclean:	clean
	$(foreach file, $(LIBS), make fclean -C $(file);)

re:	fclean all

.PHONY:	all clean fclean re
