#include "../includes/push_swap.h"

int	is_sorted(t_stack *a)
{
	t_stack	*ptr;

	ptr = a;
	while (ptr && ptr->next)
	{
		if (ptr->value > ptr->next->value)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	is_revsorted(t_stack *a)
{
	t_stack	*ptr;

	ptr = a;
	while (ptr->next)
	{
		if (ptr->value < ptr->next->value)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
