#include "../includes/push_swap.h"

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*ptr;

	if (!s)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		if (ft_strlen(s) < len)
			len = ft_strlen(s);
		ptr = (char *)malloc(len + 1);
		if (!ptr)
			return (NULL);
		while (i < len)
			ptr[i++] = s[start++];
	}
	else
		ptr = malloc(1);
	if (!ptr)
		return (ptr);
	*(ptr + i) = 0;
	return (ptr);
}

int	ft_nbr_word(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && count == 0)
		{
			count = 1;
			i++;
		}
		else if (*s == c)
			count = 0;
		s++;
	}
	return (i);
}

char	**free_sp(char **sp)
{
	int	i;

	i = 0;
	while (sp[i])
		free(sp[i++]);
	free(sp);
	return (NULL);
}

char	**ft_return(char *s, char **sp, char c)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j != 0)
			sp[k++] = ft_substr(s, i, j);
		if (j != 0 && !sp[k - 1])
			return (free_sp(sp));
		i += j;
	}
	sp[k] = NULL;
	return (sp);
}

char	**ft_split(char *s, char c)
{
	char	**sp;

	if (!s)
		return (NULL);
	sp = malloc((ft_nbr_word(s, c) + 1) * sizeof(char *));
	if (!sp)
		return (NULL);
	sp = ft_return(s, sp, c);
	free(s);
	return (sp);
}
