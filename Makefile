PUSH_SWAP = push_swap
OBJ_PS =	parsing/check_errors.o \
		parsing/func1.o \
		parsing/parse.o \
		sorting/check_sorted.o \
		sorting/list_functions.o \
		sorting/sorting.o \
		parsing/ft_split.o \
		parsing/fill_stack.o \
		sorting/three_or_less.o \
		sorting/instructions.o \
		push_swap.o

.phony: all clean fclean re

all: $(OBJ_CH) $(OBJ_PS)
	@ $(CC) -Wall -Wextra -Werror $(OBJ_PS) -o $(PUSH_SWAP)
	@ echo "\x1b[32m Project is successfully compiled \x1b[0m"

%.o : ./%.c
	@ $(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)
	@ echo "\x1b[32m Compiling object files \x1b[0m"

clean:
	@ rm -f $(OBJ_PS)

fclean: clean
	@ rm -f push_swap
	@ echo "\x1b[31m You deleted all object files in this project \x1b[0m"

re: fclean all