#include "../push_swap.h"

int	stack_size(t_stack *a)
{
	t_stack	*tmp;
	int		i;

	tmp = a;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}