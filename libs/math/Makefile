##
## EPITECH PROJECT, 2025
## Math Library
## File description:
## Makefile
##

BUILD_MSG    = 	\033[1m\033[1;32m[BUILD]:\033[0m
LIB_MSG      = 	\033[1m\033[0;35m[LIBRARIE]:\033[0m
DELETE_MSG   = 	\033[1;31m[DELETE]:\033[0m
RESET        = 	\033[0m

LIB_DIR      =  ../
BIN_DIR      =  bin

SRCS         =  Point.cpp   \
				Vector.cpp  \
				Color.cpp   \
				Ray.cpp     \

OBJS         = $(SRCS:%.cpp=$(BIN_DIR)/%.o)

NAME         = libmath.a
LIB          = -L

CFLAGS       = -g3
CXXFLAGS     = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): ${OBJS}
	@ar rc $(NAME) $(OBJS)

$(BIN_DIR)/%.o: %.cpp
	@mkdir -p $(BIN_DIR)
	@if [ "$(lastword $(SRCS))" = "$<" ]; then \
		echo "  │   │   └── $(BUILD_MSG) $<$(RESET)"; \
	else \
		echo "  │   │   ├── $(BUILD_MSG) $<$(RESET)"; \
	fi
	@$(CXX) -fPIC -c $< -o $@ $(CXXFLAGS)

clean:
	@echo "$(DELETE_MSG) math/bin $(RESET)"
	@rm -rf $(BIN_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re