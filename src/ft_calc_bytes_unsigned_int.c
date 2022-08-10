/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:05:37 by spatel            #+#    #+#             */
/*   Updated: 2022/08/10 19:52:49 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*	prints unsigned int in multiple formats
	a == 'u'	|  decimal unsigned int
	a == 'x'	|  hexadecimal lowercase format '7b3fe'
	a == 'X'	|  hexadecimal uppercase format '7B3FE'
	a == 'p'	|  memory location (hex lowercase) '0x7ff68'
*/

void	ft_print_unsigned_int(unsigned long n, char a, unsigned int base)
{
	if (n >= base)
	{
		ft_print_unsigned_int(n / base, a, base);
		ft_print_unsigned_int(n % base, a, base);
	}
	if (n < base)
	{
		if (n > 9 && (a == 'x'))
			ft_putchar(n % 16 + 87);
		else if (n > 9 && a == 'X')
			ft_putchar(n % 16 + 55);
		else
			ft_putchar(n + '0');
	}
}

/*	Calculates the bytes printed for a number in hexadecimal 
*/

int	ft_calc_bytes_unsigned_int(unsigned long n, char a)
{
	int	printed_bytes;
	int	base;

	printed_bytes = 0;
	if (a == 'u')
		base = 10;
	else
		base = 16;
	if (a == 'p')
	{
		write(1, "0x", 2);
		printed_bytes += 2;
		a = 'x';
	}
	ft_print_unsigned_int(n, a, (unsigned long)base);
	if (n == 0)
		printed_bytes++;
	while (n != 0)
	{
		n /= (unsigned long)base;
		printed_bytes++;
	}
	return (printed_bytes);
}
