/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:24:23 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/09/27 11:24:24 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_memory(t_optim *opt, t_stack *a, t_stack *b)
{
	delete_optim(&opt);
	free(opt);
	free_list(&a);
	free_list(&b);
}
