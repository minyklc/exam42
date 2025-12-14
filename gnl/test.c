#include "get_next_line.h"

int	main(void)
{
	char	*string;
	char	*s1;
	char	*s2;

	s1 = NULL;
	s2 = NULL;
	string = ft_strjoin(s1, s2);
	printf("%s\n", string);
	if (string != NULL)
		free(string);
	return (0);
}