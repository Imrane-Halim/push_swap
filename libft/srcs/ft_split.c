#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*get_word(char const *s, char c, int *i)
{
	int	start;

	while (s[*i] == c && s[*i])
		(*i)++;
	start = *i;
	while (s[*i] != c && s[*i])
		(*i)++;
	return (ft_strndup(s + start, *i - start));
}

static void	free_arr(char **arr, int arr_i)
{
	while (arr_i--)
		free(arr[arr_i]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		arr_i;
	int		count;
	int		i;

	if (s == NULL)
		return (NULL);
	count = count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (arr == NULL)
		return (NULL);
	arr_i = 0;
	i = 0;
	while (arr_i < count)
	{
		arr[arr_i] = get_word(s, c, &i);
		if (arr[arr_i] == NULL)
		{
			free_arr(arr, arr_i);
			return (NULL);
		}
		arr_i++;
	}
	arr[arr_i] = NULL;
	return (arr);
}
