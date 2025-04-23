##
## EPITECH PROJECT, 2025
## Arcade
## File description:
## Makefile
##

# LIB_DIR	=	../

# CXX	=	g++

# CXXFLAGS	=	-std=c++20 -Wall -Wextra -Werror -fno-gnu-unique -g3

# BIN_DIR	=	bin

# LIB	=	-L

# SRCS	=	Point.cpp	\
# 			Vector.cpp	\
# 			Color.cpp	\
# 			Ray.cpp		\

# OBJS	=	$(SRCS:%.cpp=$(BIN_DIR)/%.o)

# LIB	=	$(LIB_DIR)/math.a

# all:	create

# create: ${OBJS}
# 	ar rc $(LIB) $(OBJS)

# $(BIN_DIR)/%.o:	%.cpp
# 	@mkdir -p $(BIN_DIR)
# 	$(CXX) -fPIC -c $< -o $@ $(CXXFLAGS)

# clean:
# 	rm -rf $(BIN_DIR)
# 	rm $(LIB)

# fclean:	clean

# re:	fclean all

# .PHONY:	all clean fclean re


##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

LIB_DIR	=	../

BIN_DIR	=	bin

SRCS	=	Point.cpp	\
			Vector.cpp	\
			Color.cpp	\
			Ray.cpp		\

OBJS	=	$(SRCS:%.cpp=$(BIN_DIR)/%.o)

NAME	=	libmath.a

LIB	=	-L

CFLAGS	=	-g3

all: $(NAME)

$(NAME): ${OBJS}
	ar rc $(NAME) $(OBJS)

$(BIN_DIR)/%.o:	%.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) -fPIC -c $< -o $@ $(CXXFLAGS)

clean:
	rm -rf $(BIN_DIR)

fclean:clean
	rm -f $(NAME)

re: fclean all
