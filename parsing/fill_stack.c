#include "../push_swap.h"

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

void	free_stack(t_stack **head)
{
	if (*head)
	{
		if ((*head)->next)
			free_stack(&(*head)->next);
		free((*head)->next);
	}
}

void	free_memory(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
}

void	fill_stack(t_stack **a, t_stack **b, char **sp, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		push_to_stack(a, ft_atoi(*sp));
		sp++;
	}
    if (is_sorted(*a) && !b)
    {
        free_stack(a);
        exit(0);
    }
}
