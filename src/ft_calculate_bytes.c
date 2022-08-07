/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_bytes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:18:22 by spatel            #+#    #+#             */
/*   Updated: 2022/08/07 21:10:20 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*	calculates the bytes printed from a number in decimal 
	(base 10) or a number/memory address in hexadecimal 
	(base 16)
*/

int	ft_calculate_bytes(size_t n, char a, size_t base)
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
