/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:24:02 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/09/27 11:24:03 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int ac, char **av)
{
	t_info	info;
	t_stack	*a;
	t_stack	*b;
	t_optim	*opt;

	if (ac == 1)
		return (0);
	info = parse(ac, av);
	fill_stack(&a, info.sp, info.size);
	free_sp(info.sp);
	if (is_sorted(a) && !b)
	{
		free_list(&a);
		exit(0);
	}
	sorting(&a, &b, &opt, info.size);
	optimisation(&opt);
	print_opers(opt);
	free_memory(opt, a, b);
}
