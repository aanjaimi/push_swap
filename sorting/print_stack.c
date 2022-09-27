/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:24:44 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/09/27 11:24:45 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *a, t_stack *b)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = a;
	tmp2 = b;
	while (tmp1)
	{
		printf("%d\n", tmp1->value);
		tmp1 = tmp1->next;
	}
	printf("------------------------------\n");
	while (tmp2)
	{
		printf("%d\n", tmp2->value);
		tmp2 = tmp2->next;
	}
	printf("<------------------------------>\n");
}
