/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpple <minpple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:42:46 by minpple           #+#    #+#             */
/*   Updated: 2025/11/21 16:15:05 by minpple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		i;
	int		j;
	int		len;

	i = -1;
	j = -1;
	if (s1 == NULL)
		string = ft_calloc(BUFFER_SIZE, sizeof(char));
	else
	{
		len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
		string = ft_calloc(len + 1, sizeof(char));
	}
	if (string == NULL)
		return (NULL);
	while (s1 != NULL && s1[++i])
		string[++j] = s1[i];
	i = -1;
	while (s2 != NULL && s2[++i])
		string[++j] = s2[i];
	string[++j] = '\0';
	return (string);
}

char	*ft_strdup(const char *src)
{
	char	*str;
	int		size;
	int		i;

	size = ft_strlen((char *)src);
	i = 0;
	str = ft_calloc(size + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strlen(const char *s)
{
	int	index;

	index = -1;
	while (*(s + (++index)))
		;
	return (index);
}

char	*ft_strchr(const char *s, int c)
{
	char	caracter;
	int		i;

	caracter = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == caracter)
			return (((char *)s) + i);
		i++;
	}
	if (caracter == '\0')
		return (((char *)s) + i);
	return (NULL);
}

void    *ft_calloc(size_t nmemb, size_t size)
{
    size_t    i;
    size_t    total_size;
    char    *ptr;

    i = 0;
    if (nmemb == 0 || size == 0)
        return (malloc(0));
    total_size = nmemb * size;
    if (total_size / nmemb != size)
        return (NULL);
    ptr = malloc(total_size);
    if (!ptr)
        return (NULL);
    while (i < nmemb * size)
    {
        ptr[i] = 0;
        i++;
    }
    return (ptr);
}

void	ft_bzero(void *tab, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)tab)[i] = '\0';
		i++;
	}
}