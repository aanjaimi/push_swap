#include "../push_swap.h"

int	get_min_index(t_stack *a)
{
	t_stack	*ptr;
	int		min;
	int		i;
	int		index;

	ptr = a;
	index = 0;
	i = 0;
	min = 2147483647;
	while (ptr)
	{
		if (ptr->value < min)
		{
			min = ptr->value;
			index = i;
		}
		i++;
		ptr = ptr->next;
	}
	return (index);
}

void	sort_three(t_stack **a, t_optim **opt)
{
	if (get_min_index(*a) == 0
		&& (*a)->next->next->value < (*a)->next->value)
	{
		add_to_optim(opt, swap(*a, 'a'));
		add_to_optim(opt, rotate(a, 'a'));
	}
	else if (get_min_index(*a) == 1
		&& (*a)->value > (*a)->next->next->value)
		add_to_optim(opt, rotate(a, 'a'));
	else if (get_min_index(*a) == 1
		&& (*a)->value < (*a)->next->next->value)
		add_to_optim(opt, swap(*a, 'a'));
	else if (get_min_index(*a) == 2
		&& (*a)->value < (*a)->next->value)
		add_to_optim(opt, rev_rotate(a, 'a'));
	else if (get_min_index(*a) == 2
		&& (*a)->value > (*a)->next->value)
	{
		add_to_optim(opt, rotate(a, 'a'));
		add_to_optim(opt, swap(*a, 'a'));
	}
}

void	sort_rev_three(t_stack **b, t_optim **opt)
{
	if (get_min_index(*b) == 0
		&& (*b)->next->next->value < (*b)->next->value)
		add_to_optim(opt, rotate(b, 'b'));
	else if (get_min_index(*b) == 0
		&& (*b)->next->next->value > (*b)->next->value)
	{
		add_to_optim(opt, rotate(b, 'b'));
		add_to_optim(opt, swap(*b, 'b'));
	}
	else if (get_min_index(*b) == 1
		&& (*b)->value > (*b)->next->next->value)
	{
		add_to_optim(opt, rev_rotate(b, 'b'));
		add_to_optim(opt, swap(*b, 'b'));
	}
	else if (get_min_index(*b) == 1
		&& (*b)->value < (*b)->next->next->value)
		add_to_optim(opt, rev_rotate(b, 'b'));
	else if (get_min_index(*b) == 2
		&& (*b)->value < (*b)->next->value)
		add_to_optim(opt, swap(*b, 'b'));
}
