/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_bytes_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:18:22 by spatel            #+#    #+#             */
/*   Updated: 2022/08/11 15:13:52 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*	prints signed int in decimal
*/

void	ft_print_int(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		ft_print_int(n / 10);
	ft_putchar(n % 10 + '0');
}

/*	Calculates the bytes printed for a number in decimal
*/

int	ft_int(int n)
{
	int	printed_bytes;

	printed_bytes = 0;
	ft_print_int(n);
	if (n == -2147483648)
		return (11);
	if (n <= 0)
		printed_bytes++;
	while (n != 0)
	{
		n /= 10;
		printed_bytes++;
	}
	return (printed_bytes);
}
