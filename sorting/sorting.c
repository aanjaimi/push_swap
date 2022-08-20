#include "../includes/push_swap.h"

void	sorting(t_stack **a, t_stack **b, t_optim **opt, int size)
{
	if (size == 2 && get_min_index(*a) == 1)
		add_to_optim(opt, swap(*a, 'a'));
	else if (size == 3)
		sort_three(a, opt);
	else if (size == 4)
		sort_four(a, b, opt);
	else if (size == 5)
		sort_five(a, b, opt);
	else
		global_sort_a(a, b, opt, size);
}
