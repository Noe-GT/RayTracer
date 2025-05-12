##
## EPITECH PROJECT, 2025
## Arcade
## File description:
## Makefile
##

STATIC_MSG		=		\033[1m\033[1;36m[DYNAMIC]:\033[0m
BUILD_MSG		=		\033[1m\033[1;32m[BUILD]:\033[0m
DELETE_MSG		=		\033[1m\033[1;31m[DELETE]:\033[0m
##################################################################

ROOT			=		../
PLUGIN_DIR		=		$(ROOT)../../dynamic_libs_bin/

SHARED_DIR		=		$(ROOT)../shared/

SRCS			=		Translation.cpp 								\
						$(SHARED_DIR)Exceptions.cpp					\

OBJS_DIR		=		../translation_bin
OBJS			=		$(SRCS:%.cpp=$(OBJS_DIR)/%.o)

CXX				=		g++

NAME			=		$(PLUGIN_DIR)translation.so

LDFLAGS			=		-L ../../static_libs/ -lmath

UNAME_S 		= 		$(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	CXXFLAGS	+=		-std=c++20 -Wall -Wextra -g3 -Wno-error=unused-command-line-argument
else
	CXXFLAGS	+=		-std=c++20 -Wall -Wextra -Werror -fno-gnu-unique -g3
endif
##################################################################

all:	$(NAME)

$(NAME):	$(OBJS)
	@mkdir -p $(PLUGIN_DIR)
	$(CXX) -shared -o $(NAME) $(OBJS) $(LDFLAGS)

$(OBJS_DIR)/%.o:	%.cpp
	@mkdir -p $(OBJS_DIR)
	@if [ "$(lastword $(SRCS))" = "$<" ]; then 					\
		echo -e "  │   │   └── $(BUILD_MSG) $<$(RESET)"; 			\
	else 														\
		echo -e "  │   │   ├── $(BUILD_MSG) $<$(RESET)"; 			\
	fi
	$(CXX) -fPIC -c $< -o $@ $(CXXFLAGS) -I$(ROOT) -I$(SHARED_DIR)

##################################################################

clean:
	@echo -e "$(DELETE_MSG) translation/bin"
	rm -rf $(OBJS_DIR)

fclean:	clean
##################################################################

re:	fclean all

.PHONY:	all clean fclean re
