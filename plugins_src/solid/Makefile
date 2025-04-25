##
## EPITECH PROJECT, 2025
## Arcade
## File description:
## Makefile
##

BUILD_MSG    = \033[1m\033[1;32m[BUILD]:\033[0m
PLUGIN_MSG   = \033[1m\033[1;36m[PLUGIN]:\033[0m
DELETE_MSG   = \033[1;31m[DELETE]:\033[0m

ROOT         = ../../
SRCS         = APrimitive.cpp

PLUGINS      = Sphere

CXX          = g++

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	CXXFLAGS     = -std=c++20 -Wall -Wextra -Werror -g3
else
	CXXFLAGS     = -std=c++20 -Wall -Wextra -Werror -fno-gnu-unique -g3
endif

BIN_DIR      = bin
OBJS         = $(SRCS:%.cpp=$(BIN_DIR)/%.o)

all: print $(OBJS) plugins

print:
	@echo "  │   ├─$(PLUGIN_MSG) building Sphere.so $(file)...";

plugins:
	@$(foreach file,$(PLUGINS), make -C $(file) --no-print-directory;)

$(BIN_DIR)/%.o: %.cpp
	@mkdir -p $(BIN_DIR)
	@if [ "$(lastword $(SRCS))" = "$<" ]; then \
		echo "  │   │   └── $(BUILD_MSG) $<$(RESET)"; \
	else \
		echo "  │   │   ├──$(BUILD_MSG) $<$(RESET)"; \
	fi
	@$(CXX) -fPIC -c $< -o $@ $(CXXFLAGS)

clean:
	@echo "$(DELETE_MSG) solid/bin"
	@rm -rf $(BIN_DIR)
	@$(foreach file,$(PLUGINS),make clean -C $(file) --no-print-directory;)

fclean: clean

re: fclean all

.PHONY: all clean fclean re plugins