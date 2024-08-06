#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t	dst_len;
	size_t	src_len;

	src_len = 0;
	dst_len = ft_strlen(dst);
	while (src[src_len])
		dst[dst_len++] = src[src_len++];
	dst[dst_len] = '\0';
	return (dst);
}
