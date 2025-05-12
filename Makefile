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

CORE_DIR		=		src/core/

SRC_DIR			=		$(CORE_DIR)src/

SRC				=		$(SRC_DIR)main.cpp 						\
						$(SRC_DIR)RayTracer.cpp					\
						$(SRC_DIR)Pixel.cpp						\
						$(SRC_DIR)Scene.cpp						\
						$(SRC_DIR)Camera.cpp					\
						$(SRC_DIR)../dlloader/LibLister.cpp		\
						$(SHARED_DIR)Exceptions.cpp				\
						$(SRC_DIR)PluginHandler.cpp				\
						$(SRC_DIR)Parser.cpp					\
						$(SHARED_DIR)Material.cpp

OBJS_DIR		=		src/core_bin/
OBJS			=		$(SRC:%.cpp=$(OBJS_DIR)%.o)

LIB_DIR			=		src/static_libs/
LIBS_SRC		=		$(LIB_DIR)math							\

SHARED_DIR		=		src/shared/

DLLOADER_DIR	=		$(CORE_DIR)dlloader/

PLUGINS_SRC_DIR	=		src/dynamic_libs/

NAME			=		raytracer

CXX				=		g++

CXXFLAGS		=		-std=c++20 -Wall -Wextra -g3

LIBS			=		-L src/static_libs -lmath -lconfig++

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
	@$(CXX) $(CXXFLAGS) $(LCONFIG_FLAGS) -c $< -o $@ -I$(LIB_DIR) 	\
		-I$(PLUGINS_SRC_DIR) -I$(SHARED_DIR) -I$(DLLOADER_DIR) -I$(SRC_DIR)

$(NAME):	$(OBJS)
	@mkdir -p $(SRC_DIR) $(OBJS_DIR)
	@$(CXX) $(CXXFLAGS) $(LCONFIG_FLAGS) -o $(NAME) $(OBJS) $(LIBS) -I$(LIB_DIR) 			\
		-I$(PLUGINS_SRC_DIR) -I$(SHARED_DIR) -I$(DLLOADER_DIR) -I$(SRC_DIR)

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

re:	fclean all

.PHONY:	all libs plugins source clean fclean re
