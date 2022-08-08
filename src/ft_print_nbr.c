/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:18:22 by spatel            #+#    #+#             */
/*   Updated: 2022/08/08 18:46:03 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*	prints unsigned int in multiple formats
	a == 'u'	|  decimal unsigned int
	a == 'x'	|  hexadecimal lowercase format '7b3fe'
	a == 'X'	|  hexadecimal uppercase format '7B3FE'
	a == 'p'	|  memory location (hex lowercase) '0x7ff683844003'
*/

void	ft_print_unsigned(long long int n, char a, int base)
{
	if (a == 'p')
	{
		write(1, "0x", 2);
		return (ft_print_unsigned(n, 'x', 16));
	}
	if (n >= base)
	{
		ft_print_unsigned(n / base, a, base);
		ft_print_unsigned(n % base, a, base);
	}
	if (n < base)
	{
		if (n > 9 && (a == 'x' || a == 'p'))
			ft_putchar((int)n % 16 + 87);
		else if (n > 9 && a == 'X')
			ft_putchar((int)n % 16 + 55);
		else
			ft_putchar((int)n + '0');
	}
}

void	ft_print_int(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	if (n < 0)
	{
		ft_putchar('-');
		return (ft_print_int(-n));
	}
	if (n >= 10)
	{
		ft_print_int(n / 10);
		ft_print_int(n % 10);
	}
	if (n < 10)
		ft_putchar(n + '0');
}

/*	calculates the bytes printed from a number in decimal 
	(base 10) or a number/memory address in hexadecimal 
	(base 16)
*/

int	ft_print_nbr(long long int n, char a, int base)
{
	int	printed_bytes;

	printed_bytes = 0;
	if (a == 'i' || a == 'd')
	{
		ft_putchar('-');
		n *= -1;
		ft_print_int(n);
	}
	else if (a == 'u' || a == 'p' || a == 'x' || a == 'X')
		ft_print_unsigned(n, a, base);
	if (a == 'p')
		printed_bytes += 2;
	if (n <= 0)
		printed_bytes++;
	while (n != 0)
	{
		n /= base;
		printed_bytes++;
	}
	return (printed_bytes);
}
