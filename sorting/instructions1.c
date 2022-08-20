#include "../includes/push_swap.h"

void	sswap(t_stack *a, t_stack *b)
{
	swap(a, 'a');
	swap(b, 'b');
}

void	r_rotate(t_stack **a, t_stack **b)
{
	rotate(a, 'a');
	rotate(b, 'b');
}

void	r_rev_rotate(t_stack **a, t_stack **b)
{
	rev_rotate(a, 'a');
	rev_rotate(b, 'b');
}
