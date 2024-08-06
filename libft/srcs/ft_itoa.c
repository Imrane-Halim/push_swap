#include "libft.h"

static int	count_digits(long int n)
{
	if (n < 0)
		n = -n;
	if (n == 0 || n < 10)
		return (1);
	return (1 + count_digits(n / 10));
}

char	*ft_itoa(int n)
{
	char		*a;
	long int	nbr;
	int			len;

	len = count_digits(n);
	if (n < 0)
	{
		nbr = (long int)n;
		nbr = -nbr;
		len++;
	}
	else
		nbr = (long int)n;
	a = (char *)malloc(len + 1);
	if (!a)
		return (NULL);
	if (n < 0)
		a[0] = '-';
	a[len] = '\0';
	while (len-- && a[len] != '-')
	{
		a[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (a);
}
