#include "../includes/push_swap.h"

void	free_list(t_stack **head)
{
	t_stack	*curr;
	t_stack	*fre;

	curr = *head;
	while (curr)
	{		
		fre = curr;
		curr = curr->next;
		free(fre);
	}
	*head = NULL;
}

void	insert_beginning(t_stack **head, int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return ;
	new_node->value = value;
	new_node->next = *head;
	*head = new_node;
}

void	insert_end(t_stack **head, int value)
{
	t_stack	*new_node;
	t_stack	*curr;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->value = value;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	curr = *head;
	while (curr->next)
		curr = curr->next;
	curr->next = new_node;
}

void	remove_element(t_stack **head, int value)
{
	t_stack	*to_remove;
	t_stack	*curr;

	if (*head == NULL)
		return ;
	if ((*head)->value == value)
	{
		to_remove = *head;
		*head = (*head)->next;
		free(to_remove);
		return ;
	}
	curr = *head;
	while (curr->next)
	{
		if (curr->next->value == value)
		{
			to_remove = curr->next;
			curr->next = curr->next->next;
			free(to_remove);
			return ;
		}
		curr = curr->next;
	}
}
