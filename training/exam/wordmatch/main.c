#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
void	ft_wordmatch(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str2[i] && str1[j])
	{
		if (str1[j] == str2[i])
			j++;
		i++;
	}
	if (str1[j] == '\0')
		ft_putstr(str1);
	else
		write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		ft_wordmatch(argv[1], argv[2]);
	else
		write(1, "\n", 1);
	//printf("%s, %s\n", argv[1], argv[2]);
	return (0);
}