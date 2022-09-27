/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:25:37 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/09/27 11:25:38 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**join_and_split(int ac, char **av)
{
	int		i;
	char	*str;
	char	**sp;

	i = 0;
	str = ft_strdup("");
	while (++i < ac)
	{
		str = ft_strjoin(str, av[i]);
		str = ft_strjoin(str, " ");
	}
	sp = ft_split(str, ' ');
	return (sp);
}

int	counter(char **sp)
{
	int	i;

	i = 0;
	while (sp && sp[i])
		i++;
	return (i);
}

t_info	parse(int ac, char **av)
{
	t_info	info;

	info.sp = join_and_split(ac, av);
	info.size = counter(info.sp);
	check_error(info.sp, info.size);
	if (info.size == 1)
	{
		free_sp(info.sp);
		exit(0);
	}
	return (info);
}
