#include "../push_swap.h"

char	*swap(t_stack *a, char c)
{
	t_stack	*ptr;
	int		tmp;

	ptr = a;
	if (ptr == NULL || ptr->next == NULL)
		return ("");
	tmp = ptr->value;
	ptr->value = ptr->next->value;
	ptr->next->value = tmp;
	if (c == 'a')
		return ("sa");
	return ("sb");
}

char	*push_a(t_stack **a, t_stack **b)
{
	t_stack	*ptr;
	int		tmp;

	ptr = *b;
	if (!ptr)
		return ("");
	tmp = ptr->value;
	insert_beginning(a, tmp);
	remove_element(b, tmp);
	return ("pa");
}

char	*push_b(t_stack **a, t_stack **b)
{
	t_stack	*ptr;
	int		tmp;

	ptr = *a;
	if (!ptr)
		return ("");
	tmp = ptr->value;
	insert_beginning(b, tmp);
	remove_element(a, tmp);
	return ("pb");
}

char	*rotate(t_stack **head, char c)
{
	t_stack	*ptr;
	int		tmp;

	ptr = *head;
	if (ptr == NULL || ptr->next == NULL)
		return ("");
	tmp = ptr->value;
	while (ptr->next)
	{
		ptr->value = ptr->next->value;
		ptr = ptr->next;
	}
	ptr->value = tmp;
	if (c == 'a')
		return ("ra");
	return ("rb");
}

char	*rev_rotate(t_stack **head, char c)
{
	t_stack	*ptr;
	int		tmp;

	ptr = *head;
	if (ptr == NULL || ptr->next == NULL)
		return ("");
	while (ptr->next)
		ptr = ptr->next;
	tmp = ptr->value;
	remove_element(head, tmp);
	insert_beginning(head, tmp);
	if (c == 'a')
		return ("rra");
	return ("rrb");
}
