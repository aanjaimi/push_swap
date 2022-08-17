#include "../push_swap.h"

int get_min_index(t_stack *a)
{
	t_stack *ptr;
	int     min;
	int		i;
	int     index;

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
