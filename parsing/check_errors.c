#include "../includes/push_swap.h"

int	ft_atoi(char *str)
{
	int	signe;
	int	i;
	int	n;

	i = 0;
	n = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n * signe);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

long	check_dup(char **sp, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (ft_strcmp(sp[i], sp[j]) == 0)
				return (ERR);
		}
	}
	return (0);
}

long	check_non_num(char *str)
{
	int				i;
	long long		n;
	int				signe;

	i = 0;
	n = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i++] - '0';
		if (n * signe > 2147483647 || n * signe < -2147483648)
			return (ERR);
	}
	if (str[i] == '\0' && str[i - 1] == '-')
		return (ERR);
	if (str[i] && (str[i] < '0' || str[i] > '9'))
		return (ERR);
	return (n * signe);
}

void	check_error(char **sp, int size)
{
	int	i;

	i = 0;
	while (sp && sp[i] && size >= 1)
	{
		if (check_non_num(sp[i]) == ERR || check_dup(sp, size) == ERR)
		{
			free_sp(sp);
			write(2, "Error\n", 6);
			exit(0);
		}
		i++;
	}
	return ;
}
