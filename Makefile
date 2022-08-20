PUSH_SWAP = push_swap
OBJ_PS =	parsing/check_errors.o \
		parsing/func1.o \
		parsing/parse.o \
		parsing/ft_split.o \
		parsing/fill_stack.o \
		sorting/check_sorted.o \
		sorting/list_functions.o \
		sorting/sorting.o \
		sorting/get_pivot.o \
		sorting/three_or_less.o \
		sorting/five_or_less.o \
		sorting/instructions.o \
		sorting/stack_size.o \
		sorting/sort_stack.o \
		sorting/global_sort.o \
		sorting/print_stack.o \
		sorting/free_memory.o \
		optimisation/add_to_optim.o \
		optimisation/prt_functions.o \
		optimisation/optimisation.o \
		push_swap.o

all: $(OBJ_CH) $(OBJ_PS)
	@ $(CC) -Wall -Wextra -Werror $(OBJ_PS) -o $(PUSH_SWAP)

%.o : ./%.c
	@ $(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

clean:
	@ rm -f $(OBJ_PS)

fclean: clean
	@ rm -f push_swap

re: fclean all
