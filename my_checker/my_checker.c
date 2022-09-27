/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:25:54 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/09/27 11:25:55 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	msg_error(t_stack **a, t_stack **b)
{
	free_list(a);
	free_list(b);
	write(2, ER, 6);
	exit(0);
}

void	check_oper(char *oper, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(oper, SA))
		swap(*a, 'a');
	else if (!ft_strcmp(oper, SB))
		swap(*b, 'b');
	else if (!ft_strcmp(oper, SS))
		sswap(*a, *b);
	else if (!ft_strcmp(oper, PA))
		push_a(a, b);
	else if (!ft_strcmp(oper, PB))
		push_b(a, b);
	else if (!ft_strcmp(oper, RA))
		rotate(a, 'a');
	else if (!ft_strcmp(oper, RB))
		rotate(b, 'b');
	else if (!ft_strcmp(oper, RR))
		r_rotate(a, b);
	else if (!ft_strcmp(oper, RRA))
		rev_rotate(a, 'a');
	else if (!ft_strcmp(oper, RRB))
		rev_rotate(b, 'b');
	else if (!ft_strcmp(oper, RRR))
		r_rev_rotate(a, b);
	else
		msg_error(a, b);
}

void	check_operations(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		check_oper(line, a, b);
		line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_info	info;
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (0);
	info = parse(ac, av);
	fill_stack(&a, info.sp, info.size);
	free_sp(info.sp);
	check_operations(&a, &b);
	if (is_sorted(a) && !b)
		write(1, OK, 3);
	else
		write(1, KO, 3);
}
