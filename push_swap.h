#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERR -10000000000

# include<unistd.h>
# include<stdlib.h>
# include<stddef.h>
# include<stdio.h>

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
void	fill_stack(t_stack **a, t_stack **b, char **sp, int size);
//list_functions
void	insert_beginning(t_stack **head, int value);
void	insert_end(t_stack **head, int value);
void	remove_element(t_stack **head, int value);
void	free_list(t_stack **head);
//instructions
char	*swap(t_stack *a, char c);
char	*push_a(t_stack **a, t_stack **b);
char	*push_b(t_stack **a, t_stack **b);
char	*rotate(t_stack **head, char c);
char	*rev_rotate(t_stack **head, char c);
//sorting
int		is_sorted(t_stack *a);
int		is_revsorted(t_stack *a);
int		get_min_index(t_stack *a);
//optimisation
void	ft_putendl(char *s);
#endif