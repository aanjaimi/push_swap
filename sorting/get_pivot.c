#include "../push_swap.h"

void	swp(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

int	partition(int *a, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = a[high];
	i = (low - 1);
	j = low;
	while (j <= high - 1)
	{
		if (a[j] < pivot)
		{
			i++;
			swp(a + i, a + j);
		}
		j++;
	}
	swp(a + i + 1, a + high);
	return (i + 1);
}

void	quick_sort(int *a, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(a, low, high);
		quick_sort(a, low, pi - 1);
		quick_sort(a, pi + 1, high);
	}
}

int	get_pivot(t_stack *a, int size)
{
	int		len;
	int		*x;
	int		i;
	t_stack	*ptr;

	ptr = a;
	len = size;
	i = 0;
	x = (int *)malloc(sizeof(int) * size);
	while (ptr && len--)
	{
		x[i++] = ptr->value;
		ptr = ptr->next;
	}
	quick_sort(x, 0, size - 1);
	i = x[size / 2];
	free(x);
	return (i);
}