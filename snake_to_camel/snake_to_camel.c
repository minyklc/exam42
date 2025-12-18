#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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

int	check_snake(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '_' && (str[i] < 'a' && str[i] > 'z'))
			return (1);
		else if (i > 0 && str[i] == '_' && str[i - 1] == '_')
			return (2);
		else if (i == 0 && str[i] == '_')
			return (3);
		else if (!str[i + 1] && str[i] == '_')
			return (4);
		i++;
	}
	return (0);
}

int	ft_lenstr(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '_')
			j++;
		i++;
	}
	return (j);
}

char	*snake_to_camel(char *snake)
{
	int	i;
	int	j;
	char	*camel;

	i = 0;
	j = 0;
	camel = malloc(sizeof(char) * (ft_lenstr(snake) + 1));
	if (!camel)
		return (NULL);
	while (snake[i])
	{
		camel[j] = 0;
		if (snake[i] == '_')
		{
			i++;
			camel[j] -= 32;
		}
		camel[j] += snake[i];
		i++;
		j++;
	}
	//camel[j] = '\0';
	return (camel);
}

int	main(int argc, char *argv[])
{
	char	*str;

	if (argc == 2)
	{
		//printf("%d\n", check_snake(argv[1]));
		if (check_snake(argv[1]) != 0)
			write(1, "\n", 1);
		else
		{
			str = snake_to_camel(argv[1]);
			ft_putstr(str);
			free(str);
		}
	}
	write(1, "\n", 1);
	return (0);
}