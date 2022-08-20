#include "../includes/push_swap.h"

void	delete_str(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
}

void	add_to_optim(t_optim **opt, char *opr)
{
	t_optim	*head;
	t_optim	*new;

	head = *opt;
	if (!ft_strcmp(opr, ""))
		return ;
	if (!head)
	{
		(*opt) = (t_optim *)malloc(sizeof(t_optim));
		(*opt)->op = ft_strdup(opr);
		(*opt)->next = NULL;
		return ;
	}
	while (head->next)
		head = head->next;
	new = (t_optim *)malloc(sizeof(t_optim));
	new->op = ft_strdup(opr);
	new->next = NULL;
	head->next = new;
}

void	delete_from_optim(t_optim *opt)
{
	delete_str(&opt->op);
	free(opt);
	opt = NULL;
}

void	delete_optim(t_optim **opt)
{
	if (*opt)
	{
		if ((*opt)->next)
			delete_optim(&(*opt)->next);
		delete_str(&(*opt)->op);
		free((*opt)->next);
	}
}

void	print_opers(t_optim *opt)
{
	while (opt)
	{
		ft_putendl(opt->op);
		opt = opt->next;
	}
}
