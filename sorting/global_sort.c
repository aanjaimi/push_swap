/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:24:30 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/09/27 11:24:31 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	take_bake_to_a(t_stack **a, t_optim **opt, int len)
{
	if (len > stack_size(*a) / 2)
		while (stack_size(*a) - len++ > 0)
			add_to_optim(opt, rotate(a, 'a'));
	else
		while (len--)
			add_to_optim(opt, rev_rotate(a, 'a'));
}

void	take_bake_to_b(t_stack **b, t_optim **opt, int len)
{
	if (len > stack_size(*b) / 2)
		while (stack_size(*b) - len++ > 0)
			add_to_optim(opt, rotate(b, 'b'));
	else
		while (len--)
			add_to_optim(opt, rev_rotate(b, 'b'));
}

int	global_sort_b(t_stack **a, t_stack **b, t_optim **opt, int size)
{
	t_utils	var;

	var.i = 0;
	var.r = 0;
	var.p = 0;
	if (size <= 3)
		return (sort_stack_b(b, size, opt));
	var.pivot = get_pivot(*b, size);
	while (var.i++ < size)
	{
		if ((*b)->value > var.pivot && ++var.p)
			add_to_optim(opt, push_a(a, b));
		else if ((*b)->value <= var.pivot && ++var.r)
			add_to_optim(opt, rotate(b, 'b'));
	}
	global_sort_a(a, b, opt, var.p);
	take_bake_to_b(b, opt, var.r);
	global_sort_b(a, b, opt, size - var.p);
	while (var.p--)
		add_to_optim(opt, push_b(a, b));
	return (0);
}

int	global_sort_a(t_stack **a, t_stack **b, t_optim **opt, int size)
{
	t_utils	var;

	var.i = -1;
	var.r = 0;
	var.p = 0;
	if (size <= 3)
		return (sort_stack_a(a, size, opt));
	var.pivot = get_pivot(*a, size);
	while (++var.i < size)
	{
		if ((*a)->value < var.pivot && ++var.p)
			add_to_optim(opt, push_b(a, b));
		else if ((*a)->value >= var.pivot && ++var.r)
			add_to_optim(opt, rotate(a, 'a'));
	}
	take_bake_to_a(a, opt, var.r);
	global_sort_a(a, b, opt, size - var.p);
	global_sort_b(a, b, opt, var.p);
	while (var.p--)
		add_to_optim(opt, push_a(a, b));
	return (0);
}
