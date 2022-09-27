/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:25:45 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/09/27 11:25:46 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	double_remove(t_optim *fi, t_optim *se)
{
	delete_from_optim(se);
	delete_from_optim(fi);
}

void	delete_oper(t_optim **opt, char *op)
{
	t_var	v;

	while (1)
	{
		v.stop = 1;
		v.ptr = *opt;
		while (v.ptr->next && v.ptr->next->next)
		{
			v.pr = v.ptr;
			v.fi = v.pr->next;
			v.se = v.fi->next;
			if (!ft_strcmp(v.fi->op, op) && !ft_strcmp(v.se->op, op))
			{
				v.stop = 0;
				v.pr->next = v.se->next;
				double_remove(v.fi, v.se);
				v.ptr = v.pr->next;
			}
			else
				v.ptr = v.ptr->next;
		}
		if (v.stop == 1)
			break ;
	}
}

void	delete_opers(t_optim **opt, char *op1, char *op2)
{
	t_var	v;

	while (1)
	{
		v.stop = 1;
		v.ptr = *opt;
		while (v.ptr->next && v.ptr->next->next)
		{
			v.pr = v.ptr;
			v.fi = v.pr->next;
			v.se = v.fi->next;
			if ((!ft_strcmp(v.fi->op, op1) && !ft_strcmp(v.se->op, op2))
				|| (!ft_strcmp(v.fi->op, op2) && !ft_strcmp(v.se->op, op1)))
			{
				v.stop = 0;
				v.pr->next = v.se->next;
				double_remove(v.fi, v.se);
				v.ptr = v.pr->next;
			}
			else
				v.ptr = v.ptr->next;
		}
		if (v.stop == 1)
			break ;
	}
}

void	replace_opt(t_optim **opt, char *op1, char *op2, char *op)
{
	t_var	v;

	while (1)
	{
		v.stop = 1;
		v.ptr = *opt;
		while (v.ptr && v.ptr->next)
		{
			v.pr = v.ptr->next;
			if ((!ft_strcmp(v.ptr->op, op1) && !ft_strcmp(v.pr->op, op2))
				|| (!ft_strcmp(v.ptr->op, op2) && !ft_strcmp(v.pr->op, op1)))
			{
				v.stop = 0;
				v.ptr->next = v.pr->next;
				delete_from_optim(v.pr);
				v.ptr->op = ft_strdup(op);
			}
			else
				v.ptr = v.ptr->next;
		}
		if (v.stop == 1)
			break ;
	}
}

void	optimisation(t_optim **opt)
{
	delete_oper(opt, "sa");
	delete_oper(opt, "sb");
	delete_opers(opt, "pa", "pb");
	delete_opers(opt, "ra", "rra");
	delete_opers(opt, "rb", "rrb");
	replace_opt(opt, "sa", "sb", "ss");
	replace_opt(opt, "ra", "rb", "rr");
	replace_opt(opt, "rra", "rrb", "rrr");
}
