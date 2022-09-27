/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:24:54 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/09/27 11:24:55 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sorting(t_stack **a, t_stack **b, t_optim **opt, int size)
{
	if (size == 2 && get_min_index(*a) == 1)
		add_to_optim(opt, swap(*a, 'a'));
	else if (size == 3)
		sort_three(a, opt);
	else if (size == 4)
		sort_four(a, b, opt);
	else if (size == 5)
		sort_five(a, b, opt);
	else
		global_sort_a(a, b, opt, size);
}
