#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*tmp;

	tmp = s;
	while (n--)
		tmp[n] = c;
	return (tmp);
}
