##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##
STATIC_MSG		=	\033[1m\033[1;36m[DYNAMIC]:\033[0m
DELETE_MSG    	= 	\033[1;31m[DELETE]:\033[0m
##################################################################

PLUGINS_DIR		=	../dynamic_libs_bin/

PLUGINS			=	sphere										\
					SFML										\
					scaling										\
					translation									\
					rotation									\
					# directional									\
##################################################################

all:
	@$(foreach file, $(PLUGINS), echo "  │   ├─$(STATIC_MSG) 	\
		$(file)..."; make -C $(file);)
##################################################################

clean:
	@$(foreach file, $(PLUGINS), make clean -C $(file) --silent;)
	@echo "$(DELETE_MSG) plugin/bin"
	@rm -rf $(PLUGINS_DIR)*

fclean:	clean
##################################################################

re:	fclean all

.PHONY:	all build clean fclean re
