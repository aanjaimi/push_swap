#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERR -10000000000
# define ER "Error\n"
# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"
# define OK "OK\n"
# define KO "KO\n"

# include<unistd.h>
# include<stdlib.h>
# include<stddef.h>
# include<stdio.h>
# include "get_next_line.h"

typedef struct s_utils
{
	int	pivot;
	int	i;
	int	p;
	int	r;
}	t_utils;

typedef struct s_info
{
	int		size;
	char	**sp;
}	t_info;

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_optim
{
	char			*op;
	struct s_optim	*next;
}	t_optim;

typedef struct s_var
{
	t_optim	*ptr;
	t_optim	*pr;
	t_optim	*fi;
	t_optim	*se;
	int		stop;
}	t_var;

//parsing
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char *s, char c);
char	**free_sp(char **sp);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char	*src);
int		ft_strlen(char *s);
void	check_error(char **sp, int size);
t_info	parse(int ac, char **av);
void	fill_stack(t_stack **a, char **sp, int size);
//list_functions
void	insert_beginning(t_stack **head, int value);
void	insert_end(t_stack **head, int value);
void	remove_element(t_stack **head, int value);
//instructions
char	*swap(t_stack *a, char c);
char	*push_a(t_stack **a, t_stack **b);
char	*push_b(t_stack **a, t_stack **b);
char	*rotate(t_stack **head, char c);
char	*rev_rotate(t_stack **head, char c);
void	sswap(t_stack *a, t_stack *b);
void	r_rotate(t_stack **a, t_stack **b);
void	r_rev_rotate(t_stack **a, t_stack **b);
//sorting
int		get_pivot(t_stack *a, int size);
int		is_sorted(t_stack *a);
int		is_revsorted(t_stack *a);
int		get_min_index(t_stack *a);
int		stack_size(t_stack *a);
void	sort_three(t_stack **a, t_optim **opt);
void	sort_rev_three(t_stack **b, t_optim **opt);
void	sort_four(t_stack **a, t_stack **b, t_optim **opt);
void	sort_five(t_stack **a, t_stack **b, t_optim **opt);
void	sorting(t_stack **a, t_stack **b, t_optim **opt, int size);
int		sort_stack_a(t_stack **a, int size, t_optim **opt);
int		sort_stack_b(t_stack **b, int size, t_optim **opt);
int		global_sort_a(t_stack **a, t_stack **b, t_optim **opt, int size);
int		global_sort_b(t_stack **a, t_stack **b, t_optim **opt, int size);
void	print_stack(t_stack *a, t_stack *b);
//optimisation
void	add_to_optim(t_optim **opt, char *opr);
void	delete_from_optim(t_optim *opt);
void	print_opers(t_optim *opt);
void	ft_putendl(char *s);
void	delete_oper(t_optim **opt, char *op);
void	delete_opers(t_optim **opt, char *op1, char *op2);
void	replace_opt(t_optim **opt, char *op1, char *op2, char *op);
void	optimisation(t_optim **opt);
//free
void	free_list(t_stack **head);
void	delete_optim(t_optim **opt);
void	free_memory(t_optim *opt, t_stack *a, t_stack *b);
#endif