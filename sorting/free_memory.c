#include "../push_swap.h"

void	free_memory(t_optim *opt, t_stack *a, t_stack *b)
{
	delete_optim(&opt);
	free(opt);
	free_list(&a);
	free_list(&b);
}
