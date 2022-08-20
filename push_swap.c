#include "push_swap.h"

int	main(int ac, char **av)
{
	t_info	info;
	t_stack	*a;
	t_stack	*b;
	t_optim	*opt;

	if (ac == 1)
		return (0);
	info = parse(ac, av);
	fill_stack(&a, &b, info.sp, info.size);
	sorting(&a, &b, &opt, info.size);
	optimisation(&opt);
	print_opers(opt);
}
