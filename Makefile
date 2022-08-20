PUSH_SWAP = push_swap
CHECKER = checker
CFLAGS =  -Wall -Wextra -Werror
INC_PS = includes/push_swap.h
INC_CH = includes/push_swap.h includes/get_next_line.h
SRC_PS =	parsing/check_errors.c \
		parsing/func1.c \
		parsing/parse.c \
		parsing/ft_split.c \
		parsing/fill_stack.c \
		sorting/check_sorted.c \
		sorting/list_functions.c \
		sorting/sorting.c \
		sorting/get_pivot.c \
		sorting/three_or_less.c \
		sorting/five_or_less.c \
		sorting/instructions.c \
		sorting/instructions1.c \
		sorting/stack_size.c \
		sorting/sort_stack.c \
		sorting/global_sort.c \
		sorting/print_stack.c \
		sorting/free_memory.c \
		optimisation/add_to_optim.c \
		optimisation/prt_functions.c \
		optimisation/optimisation.c \
		push_swap.c
SRC_CH =	parsing/check_errors.c \
		parsing/func1.c \
		parsing/parse.c \
		parsing/ft_split.c \
		parsing/fill_stack.c \
		sorting/check_sorted.c \
		sorting/list_functions.c \
		sorting/instructions.c \
		sorting/instructions1.c \
		my_checker/my_checker.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

OBJ_PS = $(SRC_PS:.c=.o)
OBJ_CH = $(SRC_CH:.c=.o)

all: $(PUSH_SWAP) 
$(PUSH_SWAP): $(OBJ_PS) $(INC_PS)
	@ $(CC) $(CFLAGS) $(OBJ_PS) -o $(PUSH_SWAP)

bonus: $(CHECKER)
$(CHECKER): $(OBJ_CH) $(INC_CH)
	@ $(CC) $(CFLAGS) $(OBJ_CH) -o $(CHECKER)

clean:
	@ rm -f $(OBJ_PS)
	@ rm -f $(OBJ_CH)

fclean: clean
	@ rm -f push_swap
	@ rm -f checker

re: fclean all
