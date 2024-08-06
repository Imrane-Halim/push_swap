#include "libft.h"

static int	isinset(int c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (s == NULL)
		return (NULL);
	start = 0;
	while (s[start] && isinset(s[start], set))
		start++;
	end = ft_strlen(s);
	while (end > start && isinset(s[end - 1], set))
		end--;
	str = (char *)malloc(end - start + 1);
	if (str == NULL)
		return (NULL);
	ft_strncpy(str, s + start, end - start);
	return (str);
}
