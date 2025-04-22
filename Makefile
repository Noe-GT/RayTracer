##
## EPITECH PROJECT, 2024
## raytracer
## File description:
## Makefile
##

GREEN 		=	 \033[1;32m
RED 		=	 \033[1;31m
RESET 		=	 \033[0m
SUCCESS 	=	 $(GREEN)[BUILD] :$(RESET)
ERROR 		=	 $(RED)[FAILED]	:$(RESET)
CLEARMESS 	=	 $(RED)[DELETE] :$(RESET)


SRC 		=	src/main.cpp								\
				src/shared/src/Color.cpp					\
				src/shared/src/Point.cpp					\
				src/shared/src/Vector.cpp					\
				src/shared/src/Ray.cpp						\

OBJ			=  		$(SRC:.cpp=.o)

CPPFLAGS 	+=		-Wall									\
					-Wextra									\
					-std=c++20								\

LDFLAGS		=	-lsfml-graphics 							\
				-lsfml-window 								\
				-lsfml-system								\

INCLUDES 	= 		-I include

NAME 		=		raytracer

CC			= 		g++

RM			=		rm -rf

all:				$(NAME)

$(NAME): 			$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(INCLUDES) $(LDFLAGS)
	@echo "$(SUCCESS) $(NAME)"


%.o: %.cpp
	@if $(CC) $(CPPFLAGS) $(INCLUDES) -c $< -o $@; then 	\
		echo "$(SUCCESS) $<"; 								\
	else 													\
		echo "$(ERROR) $<"; 								\
		exit 1; 											\
	fi

clean:
	@for file in $(OBJ); do 								\
		if [ -f $$file ]; then 								\
			echo "$(CLEARMESS) $$file"; 					\
		fi; 												\
	done
	@$(RM) $(OBJ); 											\

fclean: clean
	@$(RM) $(NAME)
	@echo "$(CLEARMESS) $(NAME)"; 							\

	@$(RM) *.gcda
	@$(RM) *.gcno
	@$(RM) test

re:	fclean
	@$(MAKE) all --silent

debug:	CPPFLAGS += -g3
debug: 	re

.PHONY: all re clean fclean test
