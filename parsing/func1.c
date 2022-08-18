#include "../push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char	*src)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	j = -1;
	while (++j < i)
		dest[j] = src[j];
	dest[j] = 0;
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		x;

	i = -1;
	x = 0;
	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	while (++i < ft_strlen(s1))
		ptr[i] = s1[i];
	while (i < ft_strlen(s1) + ft_strlen(s2))
		ptr[i++] = s2[x++];
	ptr[i] = 0;
	free(s1);
	return (ptr);
}
