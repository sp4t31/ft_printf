/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_bytes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:18:22 by spatel            #+#    #+#             */
/*   Updated: 2022/08/01 15:53:31 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*	calculates the bytes printed from a number in decimal 
	format (base 10) or hexadecimal format (base 16)
*/

int	ft_calculate_bytes(long long n, char a, int base)
{
	int	printed_bytes;

	printed_bytes = 0;
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
