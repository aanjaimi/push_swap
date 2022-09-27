/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:24:37 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/09/27 11:24:38 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sswap(t_stack *a, t_stack *b)
{
	swap(a, 'a');
	swap(b, 'b');
}

void	r_rotate(t_stack **a, t_stack **b)
{
	rotate(a, 'a');
	rotate(b, 'b');
}

void	r_rev_rotate(t_stack **a, t_stack **b)
{
	rev_rotate(a, 'a');
	rev_rotate(b, 'b');
}
