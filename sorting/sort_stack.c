#include "../push_swap.h"

int	sort_a_three_upper(t_stack **a, t_optim **opt)
{
	int i;

	i = 0;
	while (++i < 3)
	{
		if ((*a)->value > (*a)->next->value)
			add_to_optim(opt, swap(*a, 'a'));
		add_to_optim(opt, rotate(a, 'a'));
	}
	i = 0;
	while (++i < 3)
		add_to_optim(opt, rev_rotate(a, 'a'));
	if ((*a)->value > (*a)->next->value)
		add_to_optim(opt, swap(*a, 'a'));
	return (0);
}

int	sort_b_three_upper(t_stack **b, t_optim **opt)
{
	int i;

	i = 0;
	while (++i < 3)
	{
		if ((*b)->value < (*b)->next->value)
			add_to_optim(opt, swap(*b, 'b'));
		add_to_optim(opt, rotate(b, 'b'));
	}
	i = 0;
	while (++i < 3)
		add_to_optim(opt, rev_rotate(b, 'b'));
	if ((*b)->value < (*b)->next->value)
		add_to_optim(opt, swap(*b, 'b'));
	return (0);
}

int	sort_stack_a(t_stack **a, int size, t_optim **opt)
{
	if (size == 1)
		return (0);
	else if (size == 2 && (*a)->value > (*a)->next->value)
		add_to_optim(opt, swap(*a, 'a'));
	else if (size == 3 && stack_size(*a) == 3)
		sort_three(a, opt);
	else if (size == 3)
		sort_a_three_upper(a, opt);
	return (0);
}

int	sort_stack_b(t_stack **b, int size, t_optim **opt)
{
	if (size == 1)
		return (0);
	else if (size == 2 && (*b)->value < (*b)->next->value)
		add_to_optim(opt, swap(*b, 'b'));
	else if (size == 3 && stack_size(*b) == 3)
		sort_rev_three(b, opt);
	else if (size == 3)
		sort_b_three_upper(b, opt);
	return (0);
}