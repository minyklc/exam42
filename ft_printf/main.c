/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpple <minpple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:33:42 by minpple           #+#    #+#             */
/*   Updated: 2025/11/18 16:07:44 by minpple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_type(va_list ap, char c)
{
	if (c == 'c' || c == 's' || c =='p' || c == 'd'
	|| c == 'i' || c == 'u' || c == 'x' || c == 'X'
	|| c == '%')
		return (1);
	return (0);
}

int	ft_conversion(va_list ap, char c)
{
	int	n;
	
	n = 0;
	if (c == 'c')
		n = ft_c(va_arg(ap, char));
	else if (c == 's')
		n = ft_s(va_arg(ap, char *));
	else if (c == 'p')
		n = ft_p(va_arg(ap, void *));
	else if (c == 'd')
		n = ft_d(va_arg(ap, int));
	else if (c == 'i')
		n = ft_i(va_arg(ap, int));
	else if (c == 'u')
		n = ft_u(va_arg(ap, int));
	else if (c == 'x')
		n = ft_x(va_arg(ap, int));
	else if (c == 'X')
		n = ft_X(va_arg(ap, int));
	else if (c == '%')
		n = ft_percent(va_arg(ap, char));
	return (n);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	j;
	va_list	ap;
	va_start(ap, str);

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_type(ap, str[i + 1]) == 1)
		{
			i++;
			j += ft_convsersion(ap, str[i]);
			i++;
		}
		if (str[i])
		{
			ft_putchar(str[i]);
			j++;
		}
		i++;
	}
	va_end(ap);
	return (i);
}

int	main(void)
{
	int	a;

	a = 6;
	ft_printf("hello je voudrais \nprint cette phrase %dlkjf\tkjh", a);
	return (0);
}