/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpple <minpple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:42:50 by minpple           #+#    #+#             */
/*   Updated: 2025/11/21 22:03:34 by minpple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

char	*get_next_line(int fd)
{
	//static char	next[BUFFER_SIZE + 1];
	static char	*next;
	char		*line;
	char		*buffer;
	int			nb_read;
	int			i;

	i = 0;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (next == NULL)		
		next = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	line = ft_strjoin(line, next);
	nb_read = 1;
	while ((ft_strchr(line, '\n') == NULL) && nb_read > 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		printf("%c\n", buffer[0]);
		if (nb_read < 0)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		line = ft_strjoin(line, buffer);
	}
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
	{
		next = ft_strdup(&line[i + 1]);
		ft_bzero(&line[i + 1], BUFFER_SIZE);
	}
	printf("%c\n", buffer[0]);
	return (line);
}

int	main(void)
{
	int		fd;
	int		i;
	char	*s;
	
	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i < 1)
	{
		s = get_next_line(fd);
		ft_putstr(s);
		free(s);
		i++;
	}
	close(fd);
	return (0);
}