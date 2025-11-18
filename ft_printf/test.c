#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	i;
	int	j;
	int	*p;
	void	*truc;

	i = 48;
	j = 42;
	p = &i;
	truc = &i;
	printf("%jhgjhgjzhgcdzgc", i, j);
	// printf("%d\n", i);
	// printf("%p\n", &i);
	// printf("%p\n", &truc);
	// printf("%p\n", &p);
	// printf("%d\n", *(int *)truc);
	// printf("%c\n", *(char *)p);
	return (0);
}