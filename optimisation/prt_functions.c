/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:25:48 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/09/27 11:25:49 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return ;
	while (s[++i])
		ft_putchar(s[i]);
}

void	ft_putendl(char *s)
{
	if (!s)
		return ;
	ft_putstr(s);
	ft_putchar('\n');
}
