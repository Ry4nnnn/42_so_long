#include "libft.h"

char	*ft_strchr_sl(const char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	// if (*s == (unsigned char)c)
	// 	return (s);
	return (0);
}