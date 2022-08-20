#include "../includes/push_swap.h"

void	push_to_stack(t_stack **head, int val)
{
	t_stack	*current;
	t_stack	*new;

	current = *head;
	if (current)
	{
		while (current->next)
			current = current->next;
		new = (t_stack *)malloc(sizeof(t_stack));
		new->value = val;
		new->next = NULL;
		current->next = new;
		return ;
	}
	*head = (t_stack *)malloc(sizeof(t_stack));
	(*head)->value = val;
	(*head)->next = NULL;
}

void	fill_stack(t_stack **a, char **sp, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		push_to_stack(a, ft_atoi(*sp));
		sp++;
	}
}
