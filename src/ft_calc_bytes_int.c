/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:18:22 by spatel            #+#    #+#             */
/*   Updated: 2022/08/10 19:59:52 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*	prints signed int in decimal
*/

void	ft_print_int(long int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_print_int(n / 10);
		ft_print_int(n % 10);
	}
	if (n < 10)
		ft_putchar(n + '0');
}

/*	Calculates the bytes printed for a number in decimal
*/

int	ft_calc_bytes_int(long int n)
{
	int	printed_bytes;

	printed_bytes = 0;
	ft_print_int(n);
	if (n <= 0)
		printed_bytes++;
	while (n != 0)
	{
		n /= 10;
		printed_bytes++;
	}
	return (printed_bytes);
}
