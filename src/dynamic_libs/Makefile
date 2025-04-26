##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

DELETE_MSG    = \033[1;31m[DELETE]:\033[0m
##################################################################

PLUGINS_DIR		=	../dynamic_libs_bin/

PLUGINS			=	solid										\
					light										\
##################################################################

all:
	@$(foreach file, $(PLUGINS), make -C $(file);)
##################################################################

clean:
	@$(foreach file, $(PLUGINS), make clean -C $(file) --silent;)
	@echo "$(DELETE_MSG) plugin/bin"
	@rm -f $(PLUGINS_DIR)*

fclean:	clean
##################################################################

re:	fclean all

.PHONY:	all build clean fclean re
