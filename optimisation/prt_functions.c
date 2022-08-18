#include "../push_swap.h"

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
