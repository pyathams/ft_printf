/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:38:39 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/23 03:04:47 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex_print(int n, const char type)
{
	if (n >= 16)
	{
		print_hex_print(n / 16, type);
		print_hex_print(n % 16, type);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
		{
			if (type == 'x')
				ft_putchar (n - 10 + 'a');
			else if (type == 'X')
				ft_putchar(n - 10 + 'A');
		}
	}
}

int	ft_print_hexa(int n, const char type)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		print_hex_print(n, type);
	return (llength(n, 16));
}