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

SHARED_DIR			=		src/shared/

SRC_DIR			=		src/core/
SRC				=		$(SRC_DIR)main.cpp 						\
						$(SRC_DIR)RayTracer.cpp					\
						$(SRC_DIR)../dlloader/LibLister.cpp		\
						$(SRC_DIR)Exceptions.cpp				\

OBJS_DIR		=		src/core_bin/
OBJS			=		$(SRC:%.cpp=$(OBJS_DIR)%.o)

LIB_DIR			=		src/static_libs/
LIBS_SRC		=		$(LIB_DIR)math							\

PLUGINS_SRC_DIR	=		src/dynamic_libs/

NAME			=		raytracer

CXX				=		g++

CXXFLAGS		=		-std=c++20 -Wall -Wextra -Werror -g3

SFML_FLAGS		=		-lsfml-graphics -lsfml-window -lsfml-system

LIBS			=		-L src/static_libs -lmath
##################################################################

all: libs plugins $(NAME)
	@echo ""
##################################################################

plugins:
	@make -C $(PLUGINS_SRC_DIR) --silent
	@echo "  ├─$(LIB_MSG) lib compiled !"

##################################################################

libs:
	@echo "\n$(BUILD_MSG) building Raytracer..."
	@echo "  ├─$(LIB_MSG) building libraries..."
	@$(foreach file, $(LIBS_SRC),								\
		echo "  │   ├─$(STATIC_MSG) building $(file)..." ; 		\
		make -C $(file) --silent;)

##################################################################

$(OBJS_DIR)%.o: %.cpp
	@mkdir -p $(dir $@)
	@if [ "$(lastword $(SRC))" = "$<" ]; then \
		echo "  └── $(BUILD_MSG) $<$(RESET)"; \
	else \
		echo "  ├── $(BUILD_MSG) $<$(RESET)"; \
	fi
	@$(CXX) $(CXXFLAGS) -c $< -o $@ -I$(LIBS_SRC) -I$(SRC_DIR) 	\
		-I$(PLUGINS_SRC_DIR) -I$(SHARED_DIR)

$(NAME):	$(OBJS)
	@mkdir -p $(SRC_DIR) $(OBJS_DIR)
	@$(CXX) -o $(NAME) $(OBJS) $(LIBS) -I$(LIB_DIR) 			\
		-I$(SRC_DIR) -I$(PLUGINS_SRC_DIR) -I$(SHARED_DIR)
##################################################################

clean:
	@rm -rf $(OBJS_DIR)*
	@rm -rf $(OBJS_DIR)
	@echo "$(DELETE_MSG) src/bin"
	@make clean -C $(PLUGINS_SRC_DIR) --silent
	@$(foreach file, $(LIBS_SRC), make clean -C $(file) --silent;)

fclean:	clean
	@rm -rf $(NAME)
	@rm -rf dynamic_libs_bin
	@$(foreach file, $(LIBS_SRC), make fclean -C $(file) --silent;)

re:	fclean all

.PHONY:	all libs plugins source clean fclean re
