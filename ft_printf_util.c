/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:40:09 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/23 04:27:47 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int	putstr(char *str)
{
	int	i;

	if (!str)
	{
		putstr("(null)");
		return (6);
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i++], 1);
	}
	return (i);
}

int	length(int n, int base)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n = n / base;
		i++;
	}
	return (i);
}

int	llength(long long n, int base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / base;
		i++;
	}
	return (i);
}

int	hlength(long long n)
{
	int	i;

	i = 0;
	while (n)
	{
		n = n / 16;
		i++;
	}
	return (i + 2);
}
