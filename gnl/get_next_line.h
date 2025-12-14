/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpple <minpple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:42:53 by minpple           #+#    #+#             */
/*   Updated: 2025/11/21 15:46:22 by minpple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H_
# define GNL_H_

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void	ft_bzero(void *tab, size_t n);
void    *ft_calloc(size_t nmemb, size_t size);
void	ft_putstr(char *s);
int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);

#endif