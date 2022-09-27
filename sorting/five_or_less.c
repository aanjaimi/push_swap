/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_or_less.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:24:18 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/09/27 11:24:19 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_four(t_stack **a, t_stack **b, t_optim **opt)
{
	if (get_min_index(*a) == 1)
		add_to_optim(opt, swap(*a, 'a'));
	else if (get_min_index(*a) == 2)
	{
		add_to_optim(opt, rotate(a, 'a'));
		add_to_optim(opt, rotate(a, 'a'));
	}
	else if (get_min_index(*a) == 3)
		add_to_optim(opt, rev_rotate(a, 'a'));
	add_to_optim(opt, push_b(a, b));
	sort_three(a, opt);
	add_to_optim(opt, push_a(a, b));
}

void	sort_five(t_stack **a, t_stack **b, t_optim **opt)
{
	if (get_min_index(*a) == 1)
		add_to_optim(opt, swap(*a, 'a'));
	else if (get_min_index(*a) == 2)
	{
		add_to_optim(opt, rotate(a, 'a'));
		add_to_optim(opt, rotate(a, 'a'));
	}
	else if (get_min_index(*a) == 3)
	{
		add_to_optim(opt, rev_rotate(a, 'a'));
		add_to_optim(opt, rev_rotate(a, 'a'));
	}
	else if (get_min_index(*a) == 4)
		add_to_optim(opt, rev_rotate(a, 'a'));
	add_to_optim(opt, push_b(a, b));
	sort_four(a, b, opt);
	add_to_optim(opt, push_a(a, b));
}
