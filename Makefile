##
## EPITECH PROJECT, 2025
## Raytracer
## File description:
## Makefile
##

BUILD_MSG		=		\033[1m\033[1;32m[BUILD]:\033[0m
LIB_MSG			=		\033[1m\033[1;35m[LIBS]:\033[0m
STATIC_MSG		=		\033[1m\033[1;36m[STATIC]:\033[0m
DELETE_MSG		=		\033[1m\033[1;31m[DELETE]:\033[0m
##################################################################

PLUGINS_SRC_DIR	=		plugins_src/

SRC_DIR			=		src/
SRC				=		$(SRC_DIR)main.cpp 						\
						$(SRC_DIR)RayTracer.cpp					\
						$(SRC_DIR)pluginHandling/LibLister.cpp	\
						$(SRC_DIR)Exceptions.cpp				\

OBJS_DIR		=		bin/
OBJS			=		$(SRC:%.cpp=$(OBJS_DIR)%.o)

LIB_DIR			=		libs/
LIBS_SRC		=		$(LIB_DIR)math							\

NAME			=		raytracer

CXX				=		g++

CXXFLAGS		=		-std=c++20 -Wall -Wextra -Werror -g3

SFML_FLAGS		=		-lsfml-graphics -lsfml-window -lsfml-system

LIBS			=		-L libs/math -lmath
##################################################################

all: libs plugins $(NAME)
	@echo -e ""
##################################################################

plugins:
	@make -C $(PLUGINS_SRC_DIR) --silent
	@echo -e "  ├─$(LIB_MSG) lib compiled !"

##################################################################

libs:
	@echo -e "\n$(BUILD_MSG) building Raytracer..."
	@echo -e "  ├─$(LIB_MSG) building libraries..."
	@$(foreach file, $(LIBS_SRC),								\
		echo -e "  │   ├─$(STATIC_MSG) building $(file)..." ; 		\
		make -C $(file) --silent;)

##################################################################

$(OBJS_DIR)%.o: %.cpp
	@mkdir -p $(dir $@)
	@if [ "$(lastword $(SRC))" = "$<" ]; then \
		echo -e "  └── $(BUILD_MSG) $<$(RESET)"; \
	else \
		echo -e "  ├── $(BUILD_MSG) $<$(RESET)"; \
	fi
	@$(CXX) $(CXXFLAGS) -c $< -o $@ -I$(LIB_DIR) -I$(SRC_DIR) 	\
		-I$(PLUGINS_SRC_DIR)

$(NAME):	$(OBJS)
	@mkdir -p $(SRC_DIR)$(OBJS_DIR)
	@$(CXX) -o $(NAME) $(OBJS) $(LIBS) -I$(LIB_DIR) 			\
		-I$(SRC_DIR) -I$(PLUGINS_SRC_DIR)
##################################################################

clean:
	@rm -rf $(OBJS_DIR)*
	@echo -e "$(DELETE_MSG) src/bin"
	@make clean -C $(PLUGINS_SRC_DIR) --silent
	@$(foreach file, $(LIBS_SRC), make clean -C $(file) --silent;)

fclean:	clean
	@rm -f $(NAME)
	@$(foreach file, $(LIBS_SRC), make fclean -C $(file) --silent;)

re:	fclean all

.PHONY:	all libs plugins source clean fclean re
