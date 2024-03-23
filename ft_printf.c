/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:24:37 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/23 04:04:07 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	flag_print(const char type, va_list args)
{
	if (type == 'c')
		return (print_char(args));
	else if (type == 's')
		return (putstr(va_arg(args, char *)));
	else if (type == 'p')
		return (ptr_print(va_arg(args, unsigned long)));
	else if (type == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (type == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (type == 'u')
		return (ft_put_unsigned_nbr(va_arg(args, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (ft_print_hexa(va_arg(args, unsigned int), type));
	else if (type == '%')
		ft_putchar ('%');
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += flag_print(format[i], args);
			i++;
		}
		if (!format[i])
			return (count);
		if (format[i] != '%')
		{
			count++;
			ft_putchar(format[i++]);
		}
	}
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int n = 21456324;
// 	int m;
// 	int o;
// 	ft_printf("%d \n",ft_printf("%c \n", 'h'));
// 	printf("%d \n",printf("%c \n", 'h'));
// 	ft_printf("%i \n",ft_printf("hello world \n"));
// 	printf("%i \n",printf("hello world \n"));
// 	ft_printf("%d \n",ft_printf("%% \n"));
// 	printf("%d \n",printf("%% \n"));
// 	printf("%d \n",ft_printf("%s \n", "hello"));
// 	printf("%d \n",printf("%s \n", "hello"));
// 	int s2 = printf("%d \n", n);
// 	int s1 = ft_printf("%d \n", n);
// 	printf("%d \n", s2);
// 	printf("%d \n", s1);
// 	m = printf("%p \n", &n);
// 	o = ft_printf("%p \n", &n);
// 	printf("%d \n",m);
// 	ft_printf("%d \n",o);
// 	int p = printf("%x \n", n);
// 	int q =ft_printf("%x \n", n);
// 	int r =printf("%X \n", n);
// 	int s =ft_printf("%X \n", n);
// 	printf("%d %d \n", p, r);
// 	ft_printf("%d %d \n", q, s);
// }
